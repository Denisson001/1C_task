cmake_minimum_required(VERSION 3.0)

set (
    PROJECT_NAME
    "autocompleter"
)

project( ${PROJECT_NAME} )


set (
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++17 -fsanitize=address \
	-fno-optimize-sibling-calls -fno-omit-frame-pointer -g -O1 -static-libasan"
)


set (
    SRC_EXECUTABLES
        main.cpp
        autocompleter.cpp
        parser.cpp
        trie.cpp
        driver.cpp
)


add_executable (
    ${PROJECT_NAME}
    ${SRC_EXECUTABLES}
)

