cmake_minimum_required(VERSION 3.23)
project(Emmett)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file( GLOB SRC src/*.cpp)
file( GLOB INCLUDE include/*.hpp)

add_executable(Emmett
        ${SRC}
        ${INCLUDE})

include_directories(C:/glm)
