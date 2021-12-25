# Set the project name
project (rtc_base)

# Support C++ 11
set(CMAKE_CXX_STANDARD 11)

# Set the build flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWEBRTC_POSIX -DWEBRTC_LINUX" CACHE STRING "Set C++ Compiler Flags" FORCE)

# Find the source files
aux_source_directory(${CMAKE_SOURCE_DIR}/webrtc/rtc_base/ DIR_RTC_BASE_SRCS)

# Add a library with the above sources
add_library(${PROJECT_NAME}_share SHARED ${DIR_RTC_BASE_SRCS})
add_library(${PROJECT_NAME}_static STATIC ${DIR_RTC_BASE_SRCS})

# Rename the ouput lib name
set_target_properties(${PROJECT_NAME}_share PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Set the include path
target_include_directories( ${PROJECT_NAME}_share
    PUBLIC ${PROJECT_SOURCE_DIR}/webrtc/
)

target_include_directories( ${PROJECT_NAME}_static
    PUBLIC ${PROJECT_SOURCE_DIR}/webrtc/
)
