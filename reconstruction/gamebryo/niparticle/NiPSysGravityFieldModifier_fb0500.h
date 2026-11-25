// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysGravityFieldModifier, LoadBinary: SIBLING(fo4-private@1b765c70, author-permission)
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct GravityStream;
struct GravityPoint
{
    void LoadBinary(GravityStream& stream);
    float x, y, z;
};
struct GravityFieldBase
{
    void LoadBinary(GravityStream& stream);
    std::uint8_t state[0x50];
};
struct NiPSysGravityFieldModifier : GravityFieldBase
{
    void LoadBinary(GravityStream& stream);
    void SetDirection(const GravityPoint& direction);
    GravityPoint direction;
};
