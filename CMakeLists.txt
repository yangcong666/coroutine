cmake_minimum_required(VERSION 2.8)
project (coroutine)

set(COROUTINE_CPP
	main.cpp
	coroutine.cpp
	schedule.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -O3")

add_library(COROUTINE_LIB STATIC ${COROUTINE_CPP})

add_executable(maintest ${COROUTINE_CPP})

target_link_libraries(maintest COROUTINE_LIB)
