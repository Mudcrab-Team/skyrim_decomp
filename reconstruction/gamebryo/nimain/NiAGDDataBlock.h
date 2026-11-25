// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiAGDDataBlock, FreeBuffer: SIBLING(fo4-private@1b765c70, author-permission)
// Fields and release helper: GUESS(low); stand-ins for locally observed operations
#pragma once
#include <cstdint>

struct NiAGDBufferHeader
{
    std::uint32_t size;
    void* data;
};

#pragma pack(push, 1)
struct NiAGDDataBlock
{
    NiAGDBufferHeader buffer;
    std::uint8_t ownsData;
    std::uint16_t flags;
    void FreeBuffer();
};
#pragma pack(pop)
