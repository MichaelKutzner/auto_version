cmake_minimum_required(VERSION 3.20)

project(auto_version LANGUAGES CXX)

add_executable(auto_version src/main.cpp src/version.cpp)
include_directories(include)
target_compile_features(auto_version PUBLIC cxx_std_23)
