cmake_minimum_required(VERSION 3.7)
project(xpoject_smart_calc_git)

set(CMAKE_CXX_STANDARD 11)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
set(SOURCE_FILES
        Lexer.cpp
        Lexer.hpp
        main.cpp
        Parser.cpp
        Parser.hpp
        table.cpp
        table.hpp
        AST_tree.cpp AST_tree.h)

add_executable(main ${SOURCE_FILES})