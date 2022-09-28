cmake_minimum_required(VERSION 3.11)
project(DodgeRunner)

cmake_policy(SET CMP0054 NEW)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fstack-protector-all")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fdelete-null-pointer-checks")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Load module for speeding up builds
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cotire)

# Add dependencies
include(cmake/CPM.cmake)
CPMAddPackage(
    NAME raylib
    GITHUB_REPOSITORY raysan5/raylib
    GIT_TAG 4.2.0
    VERSION 4.2.0
)

add_executable(${PROJECT_NAME} src/main.cpp src/world.cpp src/player.cpp
    src/obstacle.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} raylib)
cotire(${PROJECT_NAME})

if (MSVC)
    # Warning level 4 and warnings as errors
    add_compile_options(/W4 /Wx)
else()
    # Lots of warnings and warnings as errors
    add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror)
endif()
