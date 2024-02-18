cmake_minimum_required(VERSION 3.26)

project(PixelPicasso
        VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TEST "Build the demo" OFF)

# Set application version. For more details, see src/version.h.in
set(VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(VERSION_PATCH ${PROJECT_VERSION_PATCH})

message(STATUS "This application's version is ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

add_subdirectory(src)

if (BUILD_TEST)
    add_subdirectory(tests)
endif ()