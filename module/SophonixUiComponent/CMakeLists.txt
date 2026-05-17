cmake_minimum_required(VERSION 3.16)

project(SophonixUiComponent VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

find_package(Qt6 6.2 COMPONENTS
    Quick
    REQUIRED)

qt_add_library(SophonixUiComponent STATIC)
qt_add_qml_module(SophonixUiComponent
    URI SophonixUiComponent
    VERSION 1.0
    QML_FILES
        ./Shell/Shell.qml
        ./Shell/ShellInput.qml
        ./Shell/ShellOutput.qml
    SOURCES
        ./Shell/shellInterface.h
        ./Shell/shellInterface.cpp
        ./Shell/shellModel.h
        ./Shell/shellModel.cpp
        ./Shell/shellModelManager.h
        ./Shell/shellModelManager.cpp
)

set_target_properties(SophonixUiComponent PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(SophonixUiComponent
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(SophonixUiComponent
    PRIVATE Qt6::Quick)
target_link_libraries(SophonixUiComponent
    PUBLIC SophonixUiBasic)
target_include_directories(SophonixUiComponent
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Shell)

