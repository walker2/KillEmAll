cmake_minimum_required(VERSION 3.5)
project(KillEmAll)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${KillEmAll_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
INCLUDE(FindSDL2 REQUIRED)
INCLUDE(FindOpenGL REQUIRED)
INCLUDE(FindGLEW REQUIRED)
INCLUDE(FindSDL2_ttf REQUIRED)
INCLUDE(FindSDL2_mixer REQUIRED)

include_directories(${KillEmAll_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})

set(SOURCE_FILES
        src/Game.cpp
        src/Game.h
        src/main.cpp
        src/Actor/Actor.cpp
        src/Actor/Actor.h
        src/Actor/Human.cpp
        src/Actor/Human.h
        src/Actor/Enemy.cpp
        src/Actor/Enemy.h
        src/Level/Level.cpp
        src/Level/Level.h
        src/Actor/Player.cpp
        src/Actor/Player.h
        src/Game.cpp
        src/Game.h
        src/Weapon/Weapon.cpp
        src/Weapon/Weapon.h
        src/Weapon/RangeWeapon.cpp
        src/Weapon/RangeWeapon.h
        src/Weapon/Bullet.cpp
        src/Weapon/Bullet.h
        src/Weapon/MeleeWeapon.cpp
        src/Weapon/MeleeWeapon.h
        src/Weapon/Slash.cpp
        src/Weapon/Slash.h
        src/Decals/Blood.cpp
        src/Decals/Blood.h)

add_executable(KillEmAll ${SOURCE_FILES})
include(FindPkgConfig)
find_package(libFalconLatinum REQUIRED)
include_directories(${FALCONLATINUM_INCLUDE_DIR})
target_link_libraries(KillEmAll
        ${SDL2_LIBRARY} ${OPENGL_LIBRARIES}
        ${FALCONLATINUM_LIBRARY} ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARY} ${GLEW_LIBRARIES}
        ${BOX2D_LIBRARY})
