cmake_minimum_required(VERSION 3.8.0)

project(snn-svc VERSION 0.1.0 LANGUAGES CXX)

set(Qt5_DIR D:/Qt/Qt5.12.6/5.12.6/msvc2017_64/lib/cmake/Qt5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Network HttpServer REQUIRED) 

add_executable(server src/server.cpp)
target_link_libraries(server Qt5::Core Qt5::Network Qt5::HttpServer)

add_executable(client src/client.cpp)
target_link_libraries(client Qt5::Core Qt5::Network)