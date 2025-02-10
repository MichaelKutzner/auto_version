#include <format>
#include <iostream>

#include "version.h"

int main() {
    std::cout << std::format("Build version: {}\n", build_version.version);
    return 0;
}
