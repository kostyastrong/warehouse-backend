cmake_minimum_required(VERSION 3.20)
project(warehouse)

set(CMAKE_CXX_STANDARD 17)

add_executable(warehouse main.cpp Product.cpp Product.h Shop.cpp Shop.h Warehouse.cpp Warehouse.h Application.cpp Application.h)
