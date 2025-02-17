#include "version.h"

#include <string>
#include <string_view>

using std::operator""sv;

#if __has_include("./version_dynamic.cpp.in")

#if defined(AUTO_BUILD_VERSION)
constexpr auto version_details = std::string_view{AUTO_BUILD_VERSION};
#else
constexpr auto version_details = std::string_view{"unknown"};
#endif
#if defined(AUTO_BUILD_AUTHOR)
constexpr auto author_details = std::string_view{AUTO_BUILD_AUTHOR};
#else
constexpr auto author_details = std::string_view{"unknown|unknown"sv};
#endif

#include "./version_dynamic.cpp.in"

#else
#include "./version_static.cpp.in"
#endif
