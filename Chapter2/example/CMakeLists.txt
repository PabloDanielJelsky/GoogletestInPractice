#	example/CMakeLists.txt

#	cmake . => to generate build files
#	make => to build the project

#	To keep it clean and create all the deliveries in build sub-directory
#	1)	cmake -S . -B build && cmake --build build
#	2)	cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug && cd build && make
#	2.1)	To run release: 		./product
#	2.2)	To run test:			make test or ctest
#	2.3)	To check code coverage:	make coverage

#	Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command.
#	This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.
cmake_minimum_required(VERSION 3.1.0)
#	To start a project, we use the project() command to set the project name.
#	This call is required with every project and should be called soon after cmake_minimum_required().
#	As we will see later, this command can also be used to specify other project level information such as the language or version number.
project(product VERSION 1.0.0 LANGUAGES CXX)

message(STATUS	"Current OS       \t: ${CMAKE_SYSTEM_NAME}")
message(STATUS	"Host System      \t: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS	"Target System    \t: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS	"Compiler         \t: ${CMAKE_CXX_COMPILER}")
message(STATUS	"Compiler ID	  \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS	"Compiler Version \t: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE PROD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#	Finally, the add_executable() command tells CMake to create an executable using the specified source code files.
add_executable(${PROJECT_NAME} ${PROD_SRC})

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(
	TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})

if(NOT CMAKE_BUILD_TYPE MATCHES Release)
	enable_testing()
	add_subdirectory(test)
endif()
