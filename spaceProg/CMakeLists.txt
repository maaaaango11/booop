cmake_minimum_required(VERSION 3.15)
project(spaceProg)

set(CMAKE_CXX_STANDARD 14)

add_executable(spaceProg main.cpp IRobot.cpp IRobot.h IMode.cpp IMode.h Map.cpp Map.h Engine.cpp Engine.h Collector.cpp Collector.h Bomber.cpp Bomber.h ICommand.cpp ICommand.h Args.h Manual.cpp Manual.h AutoScan.cpp AutoScan.h AutoGrab.cpp AutoGrab.h Parser.cpp Parser.h ManualCommand.cpp ManualCommand.h)