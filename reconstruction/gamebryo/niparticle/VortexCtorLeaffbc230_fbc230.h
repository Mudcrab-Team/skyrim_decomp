// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysVortexFieldModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct VortexVectorfbc230 { float x; float y; float z; };
class VortexBasefbc230
{
public:
    VortexBasefbc230(void*, void*, void*, float, bool, float);
    virtual ~VortexBasefbc230();
    std::uint8_t state[0x48];
};
class VortexCtorLeaffbc230 : public VortexBasefbc230
{
public:
    VortexCtorLeaffbc230(void*, void*, void*, float, bool, float, const VortexVectorfbc230*);
    VortexVectorfbc230 direction;
};
