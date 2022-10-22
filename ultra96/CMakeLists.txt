cmake_minimum_required(VERSION 3.21)

project(ultra96)
set (CMAKE_CXX_STANDARD 11)
find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS sensor.proto)
add_executable(ultra96 ultra.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(ultra96 ${Protobuf_LIBRARIES})