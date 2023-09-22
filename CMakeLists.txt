cmake_minimum_required(VERSION 3.21.1)
project(Emmett)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file( GLOB SRC src/*.cpp)
file( GLOB UNIT_TEST src/unitTests/*.cpp)
file( GLOB NO_TEST src/noUnitTests/*.cpp)
file( GLOB INCLUDE include/*.hpp)
file( GLOB INCLUDE_TEST include/unitTests/*.hpp)

add_executable(Emmett
        ${NO_TEST}
        ${SRC}
        ${INCLUDE})

add_executable(EmmettUnitTests
        ${UNIT_TEST}
        ${SRC}
        ${INCLUDE}
        ${INCLUDE_TEST})

include_directories(C:/glm)
