// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysColorModifier, SetColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct ColorSetDatafaa820;
struct ColorSetTablefaa820 { void* unused; void (*destroy)(ColorSetDatafaa820*); };
struct ColorSetDatafaa820
{
    ColorSetTablefaa820* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
    std::uint32_t unknown0c;
    std::uint32_t keyCount;
    std::uint8_t unknown14[4];
    std::uint8_t* keys;
    std::uint8_t unknown20[4];
    std::uint8_t stride;
};
struct ColorSetLeaffaa820
{
    void SetColorData(ColorSetDatafaa820* replacement);
    std::uint8_t unknown00[0x30];
    ColorSetDatafaa820* data;
    std::uint32_t firstTime;
    std::uint32_t lastTime;
};
