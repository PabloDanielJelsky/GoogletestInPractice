#	test/CMakeLists.txt
cmake_minimum_required(VERSION 3.1.0)

find_package(GTest 1.10.0 CONFIG REQUIRED)

find_program(GCOV ${CMAKE_LIBRARY_ARCHITECTURE}-gcov)
find_program(LCOV lcov)
find_program(GENH genhtml)

if(GCOV AND LCOV AND GENH)
	set(COVERAGE "-coverage")
	add_custom_target(coverage
		COMMAND ${LCOV} -c -d '.' -o 'info' --ignore-errors mismatch --ignore-errors empty
		COMMAND ${LCOV} -e 'info' '*/2_aMemberFunctionTemplateInAClass/*' -o 'info' --ignore-errors mismatch --ignore-errors empty
		COMMAND ${LCOV} -r 'info' '*/test/*' -o 'info' --ignore-errors mismatch --ignore-errors empty
		COMMAND ${GENH} 'info' -o 'coverage' --filter branch --ignore-errors mismatch --ignore-errors empty)
endif()

function(create_test name)
	add_executable(${name} ${name}.cpp ${PROD_SRC})
	target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
	target_link_libraries(${name} PRIVATE GTest::gtest GTest::gmock)
	set_target_properties(${name} PROPERTIES
		COMPILE_FLAGS "${COVERAGE} -fsanitize=address -static-libasan"
		LINK_FLAGS "${COVERAGE} -fsanitize=address -static-libasan")
	add_test(NAME ${name}  COMMAND "$<TARGET_FILE:${name}>")
endfunction()

list(REMOVE_ITEM PROD_SRC ${CMAKE_SOURCE_DIR}/src/main.cpp)
create_test(gtest_main)
