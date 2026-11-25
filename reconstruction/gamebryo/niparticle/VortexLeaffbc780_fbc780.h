// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysVortexFieldModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types, fields and global: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct VortexDirection { float x, y, z; };
extern VortexDirection gVortexDefault;
class VortexFieldBase
{
public:
    VortexFieldBase();
    virtual ~VortexFieldBase();
    std::uint8_t state[0x48];
};
class VortexLeaffbc780 : public VortexFieldBase
{
public:
    VortexLeaffbc780();
    VortexDirection direction;
};
