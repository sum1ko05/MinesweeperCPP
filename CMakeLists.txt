cmake_minimum_required(VERSION 3.24)
project(HelloWorldSFML VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# According to instruction, you'll have this toolchain file after executing Conan
# Part inside if() would be probably depreciated
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    execute_process(COMMAND ${CONAN_CMD} install ${CMAKE_SOURCE_DIR} 
                    --output-folder=${CMAKE_BINARY_DIR} 
                    --build=missing
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
include("${CMAKE_BINARY_DIR}/conan_toolchain.cmake")

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

# Just find SFML after executing Conan
find_package(SFML REQUIRED COMPONENTS graphics window system)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system)