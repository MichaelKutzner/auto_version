#include "version.h"

#if __has_include("./version_dynamic.cpp.in")

#if defined(AUTO_BUILD_VERSION)
constexpr auto version_details = std::string_view{AUTO_BUILD_VERSION};
#else
constexpr auto version_details = std::string_view{"unknown"};
#endif

#include "./version_dynamic.cpp.in"

#else
#include "./version_static.cpp.in"
#endif
