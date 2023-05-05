# Makefile for project warcraft
# 2023-05-05T14:55:24
# Copyright (c) 2023 Erick Muuo. All Rights Reserved.

cmake_minimum_required(VERSION 3.2)

project(warcraft)

# find sfml libraries..
find_package(SFML 2.5 COMPONENTS graphics window audio network system REQUIRED)

# Set to build shared libraries by default
set(BUILD_SHARED_LIBS YES)


# copy all assets to the build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set(
  GAME_CORE_SOURCES
  game/game.cpp
)

add_library(
  game-core
  ${GAME_CORE_SOURCES}
)


set(
  RESOURCE_ENGINE_SOURCES
  resources/resourceHolder.cpp
)

add_library(
  resource-engine
  ${RESOURCE_ENGINE_SOURCES}
)



add_executable(warcraft main.cpp)

target_link_libraries(
  game-core

  PUBLIC

  resource-engine  sfml-window sfml-graphics sfml-network sfml-system
)

target_link_libraries(
  warcraft PUBLIC game-core
)
