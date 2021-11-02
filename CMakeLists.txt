cmake_minimum_required(VERSION 3.9.2)
project(park_c_cpp_hw)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
)
if(TEST_WEATHER)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()
set(LIB_SOURCE_FILES Weather.c WeatherInputOutput.c)
add_library(Weather STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main Weather)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_hw test_weather.cpp)
target_link_libraries(test_hw GTest::Main Weather)