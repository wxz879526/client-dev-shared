cmake_minimum_required(VERSION 3.7)

project(HelloWorld)

add_definitions(-DUNICODE -D_UNICODE)

add_executable(HelloWorld HelloWorld.cpp)

install(TARGETS HelloWorld DESTINATION bin)