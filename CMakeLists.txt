# specifiy minimum required version
cmake_minimum_required(VERSION 3.12)

# project name and version
project(my_project VERSION 1.0)

# request c++ features
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# add compiler warning flags just when building this project
# via BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Wextra;-Wshadow;-Wshadow;-Wformat=2")
set(msvc_flags "-W3")


# necessary for vim to autocomplete correctly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# call configure file
configure_file(include/Config.h.in
        "${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")

# compile source files into an executable
add_executable(my_project "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# another way to request a c++ spec
target_compile_features(my_project PUBLIC cxx_std_11)

# add options depending on the compiler used
target_compile_options(my_project PRIVATE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
 "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

# allows cmake to find the configure file
target_include_directories(my_project 
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# set output directory for executables
# config can be specified when building the project by adding:
# -DCMAKE_BUILD_TYPE=Release or -DCMAKE_BUILD_TYPE=Debug
set_target_properties(my_project 
        PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")
