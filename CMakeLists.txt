# Standard Required
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Compiling Process info
project(to_do_list)
add_executable(to_do_list.cpp )
install(TARGETS to_do_list RUNTIME DESTINATION bin)
