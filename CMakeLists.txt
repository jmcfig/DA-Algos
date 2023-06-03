cmake_minimum_required(VERSION 3.24)
project(GraphDA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphDA2 main.cpp src/Menus.cpp src/ReadCSV.cpp src/graph/Graph.cpp src/graph/VertexEdge.cpp)
