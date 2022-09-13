cmake_minimum_required(VERSION 3.11)
project(DodgeRunner)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fstack-protector-all")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fdelete-null-pointer-checks")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Download raylib game library
find_package(raylib 4.2.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.tar.gz
        )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Download Fmt string formatting library
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fmt)
find_package(fmt)

set(HEADER_FILES include/constants.h include/utils.h include/player.h include/obstacle.h)
add_executable(${PROJECT_NAME} src/main.cpp src/utils.cpp src/player.cpp src/obstacle.cpp ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} raylib fmt::fmt)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
