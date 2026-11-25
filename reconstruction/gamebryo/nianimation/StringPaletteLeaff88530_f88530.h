// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiStringPalette, IsEqual: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
class PaletteBasef88530
{
public:
    bool IsEqual(const PaletteBasef88530* other) const;
    std::uint8_t unknown00[0x10];
};
class StringPaletteLeaff88530 : public PaletteBasef88530
{
public:
    bool IsEqual(const StringPaletteLeaff88530* other) const;
    char* bytes;
    std::uint32_t length;
    std::uint32_t capacity;
};
