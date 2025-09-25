cmake_minimum_required(VERSION 3.10)
project(MAZIO_SERVER)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp main.cpp)

add_executable(mazio_server ${SOURCES}
        include/utils/Utils.h)

target_include_directories(mazio_server PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(mazio_server ws2_32)