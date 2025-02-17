#pragma  once

#include <string>

struct version {
    std::string version;
    std::string author;
    std::string author_date;
};
extern version build_version;
