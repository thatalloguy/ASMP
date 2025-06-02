cmake_minimum_required(VERSION 3.27)
project(ASMP)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)


include(Deps.cmake)

add_subdirectory(Source)
add_subdirectory(Sample)
