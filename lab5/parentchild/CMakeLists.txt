
project(parentchild)

set(HEDEAR_FILES Parent.h Child.h)
set(SOURCE_FILES Parent.cpp Child.cpp)

add_library(libparentchild STATIC ${SOURCE_FILES})
target_include_directories(libparentchild PUBLIC .)

add_executable(parentchild ${SOURCE_FILES} main.cpp)

target_link_libraries(parentchild libparentchild)