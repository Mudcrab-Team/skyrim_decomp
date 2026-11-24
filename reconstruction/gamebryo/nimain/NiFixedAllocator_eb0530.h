// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFixedAllocator, Reserve: SIBLING(fo4-private@1b765c70, author-permission)
// Fields: GUESS(low); stand-ins for offsets observed on the target
#pragma once
#include <cstddef>
#include <cstdint>

struct NiFixedAllocator
{
    std::uint8_t prefix[16];
    void* chunks;
    std::uint8_t middle[8];
    std::size_t capacity;
    void Reserve(std::size_t requested);
};
