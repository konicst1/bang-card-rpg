cmake_minimum_required(VERSION 3.15)
project(bang)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

add_executable(bang src/main.cpp src/DataLoader.cpp src/DataLoader.h src/CardFactory.cpp src/CardFactory.h src/Card.h src/RoleCard.h src/PlayCard.h src/GameManager.cpp src/GameManager.h src/Move.cpp src/Move.h src/Player.cpp src/Player.h src/UIController.cpp src/UIController.h src/SubMove.cpp src/SubMove.h src/AIPlayer.cpp src/AIPlayer.h src/Application.cpp src/Application.h src/CardBuilderPersister.cpp src/CardBuilderPersister.h src/Instruction.h src/InstructionResponse.h src/AttackInstruction.cpp src/AttackInstruction.h src/DefenseInstruction.h src/GiveCardInstruction.h)