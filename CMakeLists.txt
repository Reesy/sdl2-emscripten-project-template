cmake_minimum_required(VERSION 3.17.3) 

set(EXECUTABLE_NAME simple_example_application)

project(SFML_PROJ LANGUAGES CXX) #set the project name and to use C++

set(BUILD_SHARED_LIBS OFF)

set(SFML_BUILD_EXAMPLES OFF)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(external_resources/SFML build-sfml)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

#add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE src/main.cpp) # swap out depending on OS or if debug, maybe we want a window
add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE src/main.cpp)

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics)

# target_include_directories(${EXECUTABLE_NAME} in)
# #include project owned headers
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# #including headers that come with our external dependency SFML
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external_resources/SFML/include)