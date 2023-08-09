cmake_minimum_required(VERSION 3.21)


# set(CMAKE_C_COMPILER "/usr/bin/g++-12")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(LinkedList)

# GoogleTest requires at least C++14
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()
    
# find_package(GTest CONFIG REQUIRED)

file(GLOB SRC_FILES 
    CONFIGURE_DEPENDS
    "src/*.cc"
)

file(GLOB TEST_SRC_FILES 
    CONFIGURE_DEPENDS
    "tests/*.cpp"
)

add_executable(LinkedList src/main.cc)
target_sources(LinkedList PUBLIC ${SRC_FILES})

add_executable(LinkedListTest tests/test_linked_list.cpp)
target_sources(LinkedListTest PUBLIC src/linked_list.cc src/linked_list.h)
target_sources(LinkedListTest PUBLIC ${TEST_SRC_FILES})
# target_sources(LinkedListTest PUBLIC ${SRC_FILES})
target_link_libraries(LinkedListTest PUBLIC GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    
# gtest_discover_tests(LinkedListTest)

# add_test(AllTestLinkedList LinkedListTest)
