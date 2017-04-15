cmake_minimum_required(VERSION 3.5)

project(hello_world)

set(SOURCE_EXE main.cpp Lexer.cpp Parser.cpp table.cpp)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
add_executable(main ${SOURCE_EXE})
