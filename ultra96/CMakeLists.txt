cmake_minimum_required(VERSION 3.16)

project(ultra96)
set (CMAKE_CXX_STANDARD 14)
find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS_1 PROTO_HDRS_1 sensor.proto)
protobuf_generate_cpp(PROTO_SRCS_2 PROTO_HDRS_2 gameState.proto)
add_library(player player.cpp)
add_library(game game.cpp)
add_executable(ultra96 ultra.cpp ${PROTO_SRCS_1} ${PROTO_HDRS_1} ${PROTO_SRCS_2} ${PROTO_HDRS_2})
target_link_libraries(ultra96 ${Protobuf_LIBRARIES} game player)