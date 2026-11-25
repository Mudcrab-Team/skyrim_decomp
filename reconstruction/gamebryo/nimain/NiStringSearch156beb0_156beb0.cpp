// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156beb0 NiStringSearch156beb0::FindOneOf
#include "NiStringSearch156beb0_156beb0.h"
#include <cstring>

std::uint32_t NiStringSearch156beb0::FindOneOf(const char* characters, std::uint32_t start) const
{
    if (!characters || !*characters || !data) {
        return static_cast<std::uint32_t>(-1);
    }
    const char* found = std::strpbrk(data + start, characters);
    if (!found) {
        return static_cast<std::uint32_t>(-1);
    }
    const int offset = static_cast<int>(found - data);
    if (offset < 0) {
        return static_cast<std::uint32_t>(-1);
    }
    return static_cast<std::uint32_t>(offset);
}
