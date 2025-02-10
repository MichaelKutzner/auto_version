cmake_minimum_required(VERSION 3.20)

project(auto_version LANGUAGES CXX)

execute_process(
    COMMAND git --git-dir=${CMAKE_CURRENT_SOURCE_DIR}/.git describe --tags "--match=v[0-9]*" --long --dirty
    OUTPUT_VARIABLE git_description
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_executable(auto_version src/main.cpp src/version.cpp)
include_directories(include)
target_compile_features(auto_version PUBLIC cxx_std_23)
set_source_files_properties(src/version.cpp PROPERTIES COMPILE_DEFINITIONS AUTO_BUILD_VERSION="${git_description}")
