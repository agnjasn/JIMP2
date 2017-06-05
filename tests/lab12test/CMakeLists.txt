include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 12)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(time_recorder libtimerecorder)
add_gtest_with_memleak(tree libtree)
add_gtest_with_memleak(teacher_hash libteacherhash)
add_gtest_with_memleak(sequential_generator libsequentialgenerator)
add_gtest_with_memleak(tree_inorder libtreeiterators)
add_gtest_with_memleak(tree_preorder libtreeiterators)
add_gtest_with_memleak(tree_postorder libtreeiterators)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab12_all_tests ${SOURCE_FILES} ../../lab12/tree/Tree.cpp ../../lab12/tree/Tree.h ../../lab12/tree/TreeIterators.cpp ../../lab12/tree/TreeIterators.h ../../lab12/academiateacherhash/TeacherHash.cpp ../../lab12/academiateacherhash/TeacherHash.h ../../lab12/academiasequentialgenerator/SequentialGenerator.cpp ../../lab12/academiasequentialgenerator/SequentialGenerator.h)

target_link_libraries(lab12_all_tests ${GTEST_LIBS})
target_link_libraries(lab12_all_tests libtimerecorder)
target_link_libraries(lab12_all_tests libteacherhash)
target_link_libraries(lab12_all_tests memleak)
target_link_libraries(lab12_all_tests libtreeiterators)
target_link_libraries(lab12_all_tests libsequentialgenerator)
