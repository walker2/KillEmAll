#ifndef FALCONLATINUM_GAME_H
#define FALCONLATINUM_GAME_H
#include <vector>
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "Falcon/States/StateManager.h"
#include "Falcon/2D/Sprite.h"
#include "Falcon/GLSL/ShaderProgram.h"
#include "Falcon/2D/GLTexture.h"
#include "Falcon/Window/Window.h"
#include "Falcon/2D/Camera/Camera2D.h"
#include "Falcon/Init/Falcon.h"
#include "Falcon/2D/SpriteBatch/SpriteBatch.h"
#include "Falcon/InputOutput/InputManager.h"
#include "Falcon/Timing/Timing.h"
#include "Falcon/Object/Projectile.h"
#include "Level/Level.h"
#include "Falcon/2D/SpriteFont/SpriteFont.h"
#include "Falcon/Audio/AudioEngine.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"
#include "Weapon/Bullet.h"
#include "Decals/Blood.h"
#include "Falcon/2D/Particles/ParticleSystem.h"
#include "Falcon/2D/Particles/ParticleBatch.h"


class Game
{
public:
    Game() : m_screenWidth(1024), m_screenHeight(720), m_currentState(Falcon::StateType::PLAY),
             m_time(0), m_curLVL(0), m_player(nullptr) {};
    ~Game();
    void run();

private:
    void initSystems();
    void initLevel();
    void initShaders();
    void processInput();
    void gameLoop();
    void draw();
    void drawHUD();
    void updateActors(float deltaTime);
    void updateBullets(float deltaTime);
    void addBlood(const glm::vec2& position, int numParticles);

private:
    int m_screenWidth;
    int m_screenHeight;
    int m_curLVL;

    Falcon::Window m_window;
    Falcon::StateType m_currentState;
    Falcon::ShaderProgram m_shaderProgram;
    Falcon::Camera2D m_camera;
    Falcon::Camera2D m_hudCamera;
    Falcon::SpriteBatch m_actorSpriteBatch;
    Falcon::SpriteBatch m_decalsSpriteBatch;
    Falcon::SpriteBatch m_uiSpriteBatch;
    Falcon::InputManager m_inputManager;
    Falcon::FPSLimiter m_FPSLimiter;
    Falcon::SpriteFont* m_spriteFont;
    Falcon::AudioEngine m_audioEngine;
    Falcon::ParticleSystem m_particleSystem;
    Falcon::ParticleBatch* m_bloodEffects;

    std::vector<Level*> m_levels;
    std::vector<Human*> m_humans;
    std::vector<Enemy*> m_enemies;
    std::vector<Bullet> m_bullets;
    std::vector<Slash> m_slashes;
    std::vector<Blood> m_bloodDecals;

    Player* m_player;

    float m_FPS;
    float m_time;
};


#endif
