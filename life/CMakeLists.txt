cmake_minimum_required(VERSION 3.15)
project(life)

set(CMAKE_CXX_STANDARD 14)

add_executable(life main.cpp Cell.h Cell.cpp Field.cpp Field.h Commando.cpp Commando.h UI.cpp UI.h GameField.cpp GameField.h)