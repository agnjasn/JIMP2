
project(sumator)

set(HEDEAR_FILES Sumator.h)
set(SOURCE_FILES Sumator.cpp)

add_library(libsumator STATIC ${SOURCE_FILES})
target_include_directories(libsumator PUBLIC .)

add_executable(sumator ${SOURCE_FILES} main.cpp)

target_link_libraries(sumator libsumator)