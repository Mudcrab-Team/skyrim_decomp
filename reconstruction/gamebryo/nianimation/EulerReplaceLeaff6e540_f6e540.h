// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiEulerRotKey, ReplaceKeys: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in fields: GUESS(low); offsets and indexing observed on the target.
#pragma once
#include <cstdint>
extern void (*gEulerDestroyersf6e540[])(void*);
struct EulerReplaceLeaff6e540
{
    void ReplaceKeys(std::uint8_t axis, std::uint32_t count, void* keys);
    std::uint8_t unknown00[0x14];
    std::uint32_t counts[3];
    std::int32_t types[3];
    std::uint8_t unknown2c[4];
    void* keys[3];
    std::uint32_t cursors[3];
};
