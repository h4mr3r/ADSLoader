cmake_minimum_required(VERSION 3.26)
project(streamer)

set(CMAKE_CXX_STANDARD 23)

add_executable(streamer main.cpp
        utilities.cpp
        utilities.h
        ADS.cpp
        ADS.h
)
target_link_libraries(streamer PRIVATE ntdll.lib)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")