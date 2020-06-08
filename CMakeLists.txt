cmake_minimum_required(VERSION 3.15)
project(bang)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

add_executable(bang src/main.cpp src/DataLoader.cpp src/DataLoader.h src/CardFactory.cpp src/CardFactory.h src/Card.h src/RoleCard.h src/PlayCard.h src/GameManager.cpp src/GameManager.h src/Move.cpp src/Move.h src/Action.h src/Player.cpp src/Player.h src/UIController.cpp src/UIController.h src/AttackAction.cpp src/AttackAction.h)