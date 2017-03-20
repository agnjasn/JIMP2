include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 3)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak_stepped(smart_tree 1 2 3 4 5)

add_gtest_with_memleak_stepped(tiny_url 1 2)

add_gtest_with_memleak(c_counter libccounter)

add_gtest_with_memleak(minimal_time_difference libminimaltimedifference)

#######################################################################
##  ALL TESTS
#######################################################################


