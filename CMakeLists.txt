
cmake_minimum_required (VERSION 2.6)
project (geo-area)
add_executable(geo-area source/main.c source/polygon.c source/perimeter.c source/angle.c source/area.c source/edge_intersection.c)
add_library(m SHARED IMPORTED)
target_link_libraries(geo-area -lm)

include(CTest)
add_test (geo-area-test-onedimension0 geo-area 2:2 2:10 2:8)
set_tests_properties (geo-area-test-onedimension0 PROPERTIES PASS_REGULAR_EXPRESSION "Obliczona powierzchnia 0.000000")

add_test (geo-area-test-triangle32 geo-area 2:2 2:10 10:2)
set_tests_properties (geo-area-test-triangle32 PROPERTIES PASS_REGULAR_EXPRESSION "Obliczona powierzchnia 32.000000")

add_test (geo-area-test-square64 geo-area 2:2 2:10 10:10 10:2)
set_tests_properties (geo-area-test-square64 PROPERTIES PASS_REGULAR_EXPRESSION "Obliczona powierzchnia 64.000000")

add_test (geo-area-test-bow32 geo-area 2:2 2:10 10:2 10:10)
set_tests_properties (geo-area-test-bow32 PROPERTIES PASS_REGULAR_EXPRESSION "Obliczona powierzchnia 32.000000")

add_test (geo-area-test-usage geo-area)
set_tests_properties (geo-area-test-usage PROPERTIES PASS_REGULAR_EXPRESSION "Podaj: *")
