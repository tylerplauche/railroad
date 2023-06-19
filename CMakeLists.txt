cmake_minimum_required(VERSION 3.20)
project(Railroad)

set(CMAKE_CXX_STANDARD 14)

add_executable(Railroad main.cpp car.h dequeInterface.h deque.h station.h vector.h cmake-build-debug/stack.h queue.h)
