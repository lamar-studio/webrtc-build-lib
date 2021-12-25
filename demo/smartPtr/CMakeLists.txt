project(test)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g" CACHE STRING "Set C++ Compiler Flags" FORCE)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories( ${PROJECT_NAME}
	    PUBLIC ${PROJECT_SOURCE_DIR}
)
