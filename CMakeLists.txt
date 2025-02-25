cmake_minimum_required(VERSION 3.17)
project(Book_Library)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add executable
add_executable(Book_Library main.cpp src/Book_Interface.cpp src/Library_Interface.cpp src/Storage_Interface.cpp)
