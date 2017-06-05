

project(tree)

set(HEDEAR_FILES Tree.h)
set(SOURCE_FILES Tree.cpp)

add_library(libtree STATIC ${SOURCE_FILES})
target_include_directories(libtree PUBLIC .)
add_library(libtreeiterators STATIC TreeIterators.cpp)
target_include_directories(libtreeiterators PUBLIC .)

add_executable(tree ${SOURCE_FILES} TreeIterators.cpp main.cpp)

target_link_libraries(libtreeiterators libtree)
target_link_libraries(tree libtreeiterators)