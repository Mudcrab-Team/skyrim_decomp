// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xeaefd0 SearchPathLeafeaefd0::SetFilePath
#include "SearchPathLeafeaefd0_eaefd0.h"
#include <cstring>

void SearchPathLeafeaefd0::SetFilePath(const char* file)
{
    if (file && *file) {
        strncpy_s(path, sizeof(path), file, sizeof(path) - 1);
        NormalizeSearchPath(path);
    } else {
        path[0] = '\0';
    }
}
