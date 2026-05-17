cmake_minimum_required(VERSION 3.16)

project(SophonixUi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_library(SophonixUi STATIC)
qt_add_qml_module(SophonixUi
    URI SophonixUi
    VERSION 1.0
    QML_FILES
        ./Window/UiWindow.qml
        ./Window/UiShell/UiShell.qml
        ./Window/UiShell/UiShellBackCorner.qml
        ./Window/UiShell/UiShellBackground.qml
        ./Window/UiShell/UiShellSurface.qml
    SOURCES
        ./Window/UiWindowInterface.h
        ./Window/UiWindowInterface.cpp
)

set_target_properties(SophonixUi PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(SophonixUi
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(SophonixUi
    PRIVATE Qt6::Quick)
target_link_libraries(SophonixUi
    PUBLIC SophonixUiComponent)
target_include_directories(SophonixUi
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Window
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/FullScreen)

