cmake_minimum_required(VERSION 3.15)
project(bang)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

add_executable(bang src/main.cpp src/DataLoader.cpp src/DataLoader.h src/CardFactory.cpp src/CardFactory.h src/Card.h src/RoleCard.h src/PlayCard.h src/GameManager.cpp src/GameManager.h src/Move.cpp src/Move.h src/Action.h src/Player.cpp src/Player.h src/UIController.cpp src/UIController.h src/AttackAction.cpp src/AttackAction.h src/DefenseAction.cpp src/DefenseAction.h src/DonorAction.cpp src/DonorAction.h src/SubMove.cpp src/SubMove.h src/AIPlayer.cpp src/AIPlayer.h src/Application.cpp src/Application.h src/CardBuilderPersister.cpp src/CardBuilderPersister.h src/Instruction.h src/CardResponse.h src/AttackInstruction.cpp src/AttackInstruction.h)