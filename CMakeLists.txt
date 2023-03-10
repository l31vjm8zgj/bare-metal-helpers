cmake_minimum_required(VERSION 3.0.0)
project(unit-tests VERSION 0.1.0)

#include(CTest)
#enable_testing()

set(src
    # units
    src/date-time/date_time.c
    src/fixed-point-int/fixed_point_int.c
    # tests
    test/main.cpp
    test/test_date_time.cpp
    test/test_fixed_point_int.cpp
)

add_executable(unit-tests ${src})
target_include_directories(unit-tests PRIVATE src/)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
