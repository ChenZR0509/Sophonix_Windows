cmake_minimum_required(VERSION 3.16)

project(AtomixCli LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(AtomixCli SHARED
  ./include/cliLog.h
  ./include/cliConfig.h
  ./include/cliCommand.h
  ./include/cliPipeline.h
  ./src/cliLog.c
  ./src/cliConfig.c
  ./src/cliCommand.c
  ./src/cliPipeline.c
  AtomixCli_global.h
  atomixcli.cpp
  atomixcli.h
)

target_link_libraries(AtomixCli PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(AtomixCli PRIVATE ATOMIXCLI_LIBRARY)

target_include_directories(AtomixCli
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
