#include "version.h"

#if __has_include("./version_dynamic.cpp.in")
#include "./version_dynamic.cpp.in"
#else
#include "./version_static.cpp.in"
#endif
