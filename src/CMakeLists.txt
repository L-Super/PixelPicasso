# configure version
configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h @ONLY)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

get_target_property(QMakeExecutable Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
get_filename_component(QtBinDir "${QMakeExecutable}" DIRECTORY)
find_program(QT_DEPLOY_EXECUTABLE windeployqt macdeployqt HINTS "${QtBinDir}")

message(STATUS "Qt deployment tool: ${QT_DEPLOY_EXECUTABLE}")

if (WIN32 AND MSVC)
    # Set utf-8 encode for building on MSVC
    add_compile_options(/utf-8)
endif ()

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(logic)
add_subdirectory(widget)
add_subdirectory(widget/style)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Running ${CMAKE_BUILD_TYPE} mode")
    else ()
        message(STATUS "Running ${CMAKE_BUILD_TYPE} mode")
        # Remove the terminal display
        set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    endif ()
elseif (APPLE)
    # It needs after add_executable
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/third_party)

include(FetchContent)
FetchContent_Declare(spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(spdlog)

target_link_libraries(${PROJECT_NAME}
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        spdlog::spdlog_header_only
)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME}
            POST_BUILD
            # Deploy the Qt Application
            COMMAND ${QT_DEPLOY_EXECUTABLE}
            --no-translations
            "$<TARGET_FILE:${PROJECT_NAME}>"
    )
elseif (APPLE)
    add_custom_command(TARGET ${PROJECT_NAME}
            POST_BUILD
            COMMAND ${QT_DEPLOY_EXECUTABLE}
            "$<TARGET_BUNDLE_DIR:${PROJECT_NAME}>"
            # -dmg
    )
endif ()