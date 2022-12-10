cmake_minimum_required (VERSION 3.0)
project (RSG-Math)

include_directories (
	./include/
	)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")

# set compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# if COMPILE_EXAMPLES is set to ON, compile the examples
option(COMPILE_EXAMPLES "Compile the examples" ON)

add_executable(example1
	src/vector.cpp
	src/example0x01.cpp
)



