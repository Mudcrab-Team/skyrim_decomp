// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156be60 StringReverseLeaf156be60::FindReverse
#include "StringReverseLeaf156be60_156be60.h"
#include <cstring>

std::uint32_t StringReverseLeaf156be60::FindReverse(char character) const
{
    if (!data) {
        return static_cast<std::uint32_t>(-1);
    }
    const char* found = std::strrchr(data, character);
    if (!found || !character) {
        return static_cast<std::uint32_t>(-1);
    }
    const int offset = static_cast<int>(found - data);
    if (offset < 0) {
        return static_cast<std::uint32_t>(-1);
    }
    return static_cast<std::uint32_t>(offset);
}
