cmake_minimum_required(VERSION 3.20)
project(PhysicsEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)

add_executable(Axion
  ./src/main.cpp
  ./src/vec3.cpp
)

target_include_directories(Axion
  PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(Axion
  PRIVATE
  SDL3::SDL3
)

set_target_properties(Axion
  PROPERTIES
  INSTALL_RPATH_USE_LINK_PATH TRUE
)
