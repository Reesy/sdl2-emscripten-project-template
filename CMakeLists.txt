cmake_minimum_required(VERSION 3.17.3) 

set(EXECUTABLE_NAME simple_sdl2_application)

project(SDL2_example LANGUAGES CXX) #set the project name and to use C++

set(CMAKE_BUILD_TYPE Debug)

set(MY_SOURCES src/main.cpp)

set(MY_RESOURCES resources)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    find_package(SDL2 REQUIRED)

    find_package(SDL2_image REQUIRED)

    include_directories(${SDL2_IMAGE_INCLUDE_DIR})

    include_directories(${SDL2_INCLUDE_DIR})
endif()

add_executable(${EXECUTABLE_NAME} ${MY_SOURCES})

file(COPY ${MY_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})

if (MSVC)
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS "-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_FREETYPE=1 --preload-file resources/example_texture.png")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    file(COPY "index.html" DESTINATION ${CMAKE_BINARY_DIR})
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    target_link_libraries(${EXECUTABLE_NAME})
else()
    target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
endif()