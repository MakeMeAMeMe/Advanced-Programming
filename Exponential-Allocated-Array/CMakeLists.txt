cmake_minimum_required(VERSION 3.21)

project(ExponentialAllocatedArray)

# GoogleTest requires at least C++14
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()
    
file(
  GLOB SRC_FILES 
  CONFIGURE_DEPENDS
  "src/**/*.cc"
)

file(
  GLOB TEST_SRC_FILES 
  CONFIGURE_DEPENDS
  "tests/*.cpp"
)

add_executable(ExponentialAllocatedArray src/main.cc)
target_sources(ExponentialAllocatedArray PUBLIC ${SRC_FILES})
target_link_libraries(ExponentialAllocatedArray LinkedListLib)

add_library(ExponentialAllocatedArrayLib SHARED ${SRC_FILES})

add_executable(ExponentialAllocatedArrayTest tests/test_linked_list.cpp)
target_sources(ExponentialAllocatedArrayTest PUBLIC ${TEST_SRC_FILES})
target_link_libraries(ExponentialAllocatedArrayTest PUBLIC GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    
