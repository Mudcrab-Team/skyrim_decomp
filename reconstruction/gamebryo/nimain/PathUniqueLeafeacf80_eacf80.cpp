// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xeacf80 PathUniqueLeafeacf80::IsUniqueAbsolute
#include "PathUniqueLeafeacf80_eacf80.h"
#include <cstring>

bool PathUniqueLeafeacf80::IsUniqueAbsolute(const char* path)
{
    if (HasSpecialForm(path)) {
        return false;
    }
    const char* normalized = Normalize(path);
    if (std::strstr(normalized, gPathPatternEeacf80)) {
        return false;
    }
    char buffer[0x104];
    strcpy_s(buffer, sizeof(buffer), normalized);
    return true;
}
