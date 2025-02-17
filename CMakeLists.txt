cmake_minimum_required(VERSION 3.20)

project(auto_version LANGUAGES CXX)

execute_process(
    COMMAND git --git-dir=${CMAKE_CURRENT_SOURCE_DIR}/.git describe --tags "--match=v[0-9]*" --long --dirty
    OUTPUT_VARIABLE git_description
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND git --git-dir=${CMAKE_CURRENT_SOURCE_DIR}/.git log --max-count 1 "--format=%ai|%an (%ae)" HEAD
    OUTPUT_VARIABLE git_author
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_executable(auto_version src/main.cpp src/version.cpp)
include_directories(include)
target_compile_features(auto_version PUBLIC cxx_std_23)
target_compile_definitions(auto_version PRIVATE AUTO_BUILD_VERSION="${git_description}" AUTO_BUILD_AUTHOR="${git_author}")
