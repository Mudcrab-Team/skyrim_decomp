// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSPSysRecycleBoundModifier, LoadBinary: SIBLING(fo4-private@1b765c70, author-permission)
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct RecycleStream { void ReadLinkID(); };
struct RecyclePoint
{
    void LoadBinary(RecycleStream& stream);
    float x, y, z;
};
struct RecycleModifierBase
{
    void LoadBinary(RecycleStream& stream);
    std::uint8_t state[0x30];
};
struct BSPSysRecycleBoundModifier : RecycleModifierBase
{
    void LoadBinary(RecycleStream& stream);
    RecyclePoint offset;
    RecyclePoint extents;
};
