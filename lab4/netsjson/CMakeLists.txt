
project(simplejson)

set(HEDEAR_FILES SimpleJson.h View.h)
set(SOURCE_FILES SimpleJson.cpp View.cpp)

add_library(libsimplejson STATIC ${SOURCE_FILES})
target_include_directories(libsimplejson PUBLIC .)

add_executable(simplejson ${SOURCE_FILES} main.cpp View.cpp View.h)

target_link_libraries(simplejson libsimplejson)