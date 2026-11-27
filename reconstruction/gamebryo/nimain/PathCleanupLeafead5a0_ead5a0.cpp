// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xead5a0 PathCleanupLeafead5a0::RemoveSlashDotSlash
#include "PathCleanupLeafead5a0_ead5a0.h"
#include <cstring>

void PathCleanupLeafead5a0::RemoveSlashDotSlash(char* path)
{
    char pattern[] = "\\.\\";
    char* match = std::strstr(path, pattern);
    while (match) {
        strcpy_s(match, std::strlen(match), match + 2);
        match = std::strstr(path, pattern);
    }
}
