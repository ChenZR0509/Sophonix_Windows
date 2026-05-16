cmake_minimum_required(VERSION 3.16)

project(SophonixUiBasic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

find_package(Qt6 6.8 COMPONENTS
    Quick
    REQUIRED)

qt_add_library(SophonixUiBasic STATIC)
qt_add_qml_module(SophonixUiBasic
    URI SophonixUiBasic
    VERSION 1.0
    QML_FILES
        ./qml/UiButton.qml
        ./qml/UiText.qml
        ./qml/UiView.qml
    SOURCES
        ./cpp/include/colorScheme.h
        ./cpp/include/sizeScheme.h
        ./cpp/include/uiGlobalData.h
        ./cpp/include/uiDataType.h
        ./cpp/src/colorScheme.cpp
        ./cpp/src/sizeScheme.cpp
        ./cpp/src/uiGlobalData.cpp
)

set_target_properties(SophonixUiBasic PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(SophonixUiBasic
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(SophonixUiBasic
    PRIVATE Qt6::Quick)

target_include_directories(SophonixUiBasic
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include)

