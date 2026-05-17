cmake_minimum_required(VERSION 3.16)

project(SophonixCore LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
  Core
  Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
  Core
  Quick)

add_library(SophonixCore STATIC
  sophonixCore.h
  sophonixCore.cpp
  ./include/timeLimiter.h
  ./src/timeLimiter.cpp
  ./include/interface.h
  ./src/interface.cpp
  ./include/uiRefresh.h
  ./src/uiRefresh.cpp
)

target_link_libraries(SophonixCore
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
  PRIVATE Qt${QT_VERSION_MAJOR}::Quick)
target_link_libraries(SophonixCore
  PUBLIC SophonixUi
  PUBLIC AtomixThread)


target_compile_definitions(SophonixCore PRIVATE SOPHONIXCORE_LIBRARY)

target_include_directories(SophonixCore
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
