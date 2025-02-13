cmake_minimum_required(VERSION 3.14)
 project("BloomFilter") 
 set(CMAKE_CXX_STANDARD 14)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 include(FetchContent)
 FetchContent_Declare(
 googletest
 URL
 https://github.com/google/googletest/archive/03597a01ee50ed
 33e9dfd640b249b4be3799d395.zip
 )
 enable_testing()
 set(SOURCE_FILES # this is where the code we want to test
 src/BloomFilter.cpp
 )
 set(TEST_FILES
 tests/test_main.cpp # this is the main for tests
 # thsese files contain the tests
 tests/bloomfilter_test.cpp 
 )
 add_executable(BloomfilterTests ${TEST_FILES})
# Link Google Test and pthread to the test executable
 target_link_libraries(BloomfilterTests PRIVATE gtest gtest_main pthread)
 # Include the source directory for tests
 target_include_directories(BloomfilterTests PRIVATE src)
 include(GoogleTest)
 gtest_discover_tests(BloomfilterTests)