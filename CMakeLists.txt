cmake_minimum_required(VERSION 3.7)
SET(CMAKE_CXX_COMPILER /usr/local/bin/g++-7)
project(redis_client)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

include_directories(/usr/local/include)

add_executable(redis_client ${SOURCE_FILES})

target_link_libraries(redis_client hiredis)