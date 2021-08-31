cmake_minimum_required(VERSION 3.20)
project(item_shop)

set(CMAKE_CXX_STANDARD 14)

add_executable(item_shop main.cpp Item.cpp Item.h Shop.cpp Shop.h Player.cpp Player.h)
