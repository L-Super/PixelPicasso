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

message(STATUS "Qt version is ${QT_VERSION}")

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(logic)
add_subdirectory(widget)
add_subdirectory(widget/style)

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
    get_target_property(QMakeExecutable Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    get_filename_component(QtBinDir "${QMakeExecutable}" DIRECTORY)
    find_program(QT_DEPLOY_EXECUTABLE windeployqt HINTS "${QtBinDir}")

    add_custom_command(TARGET ${PROJECT_NAME}
            POST_BUILD
            # Deploy the Qt Application
            COMMAND ${QT_DEPLOY_EXECUTABLE}
            --no-translations
            --no-compiler-runtime
            $<TARGET_FILE:${PROJECT_NAME}>
    )
endif ()