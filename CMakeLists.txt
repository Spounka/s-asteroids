cmake_minimum_required(VERSION 3.10)
project(SAsteroids)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

include_directories("include")

add_subdirectory("extern/SFML-2.5.1")
include_directories("extern/SFML-2.5.1/include")

set(PROJECT_HEADERS "include/config.hpp" "include/resourcesmanager.hpp"
                    "include/ship.hpp")

set(PROJECT_SOURCES "src/main.cpp" "src/resourcesmanager.cpp" "src/ship.cpp")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics sfml-audio)

set(RES_DIR "${CMAKE_BINARY_DIR}/resouces")

configure_file("${CMAKE_SOURCE_DIR}/config.hpp.in"
               "${CMAKE_SOURCE_DIR}/include/config.hpp")

add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/resources"
          "${RES_DIR}")
