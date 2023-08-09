cmake_minimum_required (VERSION 3.27.1)
project (main)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wextra -Werror")


set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FullOutputDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FullOutputDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FullOutputDir})


add_executable(${PROJECT_NAME} src/main.cc)




