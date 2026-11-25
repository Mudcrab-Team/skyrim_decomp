// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiOBBNode: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in type and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

class OBBLeaff3ebf0
{
public:
    virtual ~OBBLeaff3ebf0();
    std::uint8_t unknown08[0x80];
    OBBLeaff3ebf0* left;
    OBBLeaff3ebf0* right;
};
