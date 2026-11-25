// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiIntegersExtraData, IsEqual: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// NiIntegersExtraData layout: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in types and fields: GUESS(low)
#pragma once
#include <cstdint>

struct IntegerExtraLeaff12710
{
    bool IsEqual(const IntegerExtraLeaff12710* other) const;
    std::uint8_t unknown00[0x18];
    std::uint32_t count;
    std::int32_t* values;
};
