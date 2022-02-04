cmake_minimum_required(VERSION 3.21)
project(Pasjans)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pasjans main.cpp card.h deck.h board.h play.h)
target_link_options(Pasjans PRIVATE -static-libgcc -static-libstdc++)
