#[[
 @ ProjectName: Sophonix
 @ Author: ChenZR
 @ Brief: 智子系统
 @ Date: 2026年5月10日
 ]]
cmake_minimum_required(VERSION 3.16)

project(Sophonix VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appSophonix
    main.cpp
)

qt_add_qml_module(appSophonix
    URI Sophonix
    VERSION 1.0
    QML_FILES
        Main.qml
    RESOURCES
        resource/resSophonix.qrc
)

if(WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resource/image/logo.rc")
    target_sources(appSophonix PRIVATE ${APP_ICON_RESOURCE_WINDOWS})
endif()

set_target_properties(appSophonix PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSophonix
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appSophonix
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(appSophonix
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/module/SophonixCore
)

add_subdirectory(module/SophonixUi)
add_subdirectory(module/SophonixUiBasic)
add_subdirectory(module/SophonixUiComponent)

add_subdirectory(module/SophonixCore)

target_link_libraries(appSophonix
    PRIVATE SophonixCore
)

add_subdirectory(utility/AtomixCli)
add_subdirectory(utility/AtomixThread)
