cmake_minimum_required(VERSION 3.28)
project(pluginregistry)

set(CMAKE_CXX_STANDARD 20)

add_library(common STATIC common.cpp)
set_target_properties(common PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(pluginregistry main.cpp)
set_target_properties(pluginregistry PROPERTIES ENABLE_EXPORTS ON)
target_link_libraries(pluginregistry common)

add_library(plugin SHARED plugin.cpp)
target_link_libraries(plugin common)

add_dependencies(pluginregistry plugin)
