#	CMakeLists.txt

#	Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command.
#	This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.
cmake_minimum_required(VERSION 3.1.0)
#	To start a project, we use the project() command to set the project name.
#	This call is required with every project and should be called soon after cmake_minimum_required().
#	As we will see later, this command can also be used to specify other project level information such as the language or version number.
project(product VERSION 1.0.0 LANGUAGES CXX)

find_package(GTest 1.10.0 CONFIG REQUIRED)

message(STATUS	"Current OS       \t: ${CMAKE_SYSTEM_NAME}")
message(STATUS	"Host System      \t: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS	"Target System    \t: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS	"Compiler         \t: ${CMAKE_CXX_COMPILER}")
message(STATUS	"Compiler ID	  \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS	"Compiler Version \t: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 11)

function(create_test name)
	add_executable(${name} ${name}.cpp ${PROD_SRC})
	target_link_libraries(${name} PRIVATE GTest::gtest GTest::gmock)
	add_test(NAME ${name}  COMMAND "$<TARGET_FILE:${name}>")
endfunction()

if(NOT CMAKE_BUILD_TYPE MATCHES Release)
	enable_testing()
endif()

create_test(gtest_main)
