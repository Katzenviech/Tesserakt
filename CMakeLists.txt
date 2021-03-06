cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(SOURCES src/main.cpp src/Renderer.cpp src/Controller.cpp src/Player.cpp src/Game.cpp src/Asset.cpp src/Bullet.cpp src/Enemy.cpp)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/")

project(Tesserakt)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} src)

add_executable(Tesserakt ${SOURCES})

if (WIN32)
target_link_libraries(Tesserakt ${SDL2_LIBRARY} -static gcc stdc++ winpthread -dynamic)
endif (WIN32)

if (UNIX)
target_link_libraries(Tesserakt ${SDL2_LIBRARY})
endif (UNIX)