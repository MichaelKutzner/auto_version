#include <format>
#include <iostream>

#include "version.h"

int main() {
    std::cout << std::format("Build version: {}\nAuthor: {}\nDate: {}\n", build_version.version, build_version.author, build_version.author_date);
    return 0;
}
