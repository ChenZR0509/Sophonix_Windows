cmake_minimum_required(VERSION 3.16)

project(AtomixThread LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(AtomixThread SHARED
  AtomixThread_global.h
  ./include/runnableThread.h
  ./src/runnableThread.cpp
)

target_link_libraries(AtomixThread PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(AtomixThread PRIVATE ATOMIXTHREAD_LIBRARY)

target_include_directories(AtomixThread
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
