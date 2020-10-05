cmake_minimum_required(VERSION 3.17.3) 

set(EXECUTABLE_NAME simple_sdl2_application)

project(SDL2_example LANGUAGES CXX) #set the project name and to use C++

set(CMAKE_BUILD_TYPE Debug)

set(MY_SOURCES src/main.cpp)

set(MY_RESOURCES resources)

add_executable(${EXECUTABLE_NAME} ${MY_SOURCES})

file(COPY ${MY_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/external_resources/SDL-mirror)

include_directories(${PROJECT_SOURCE_DIR}/external_resources/SDL-mirror/include)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE SDL2-static)
