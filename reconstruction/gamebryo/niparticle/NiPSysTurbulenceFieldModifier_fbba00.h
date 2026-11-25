// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysTurbulenceFieldModifier, NiPSysFieldModifier: SIBLING(fo4-private@1b765c70, author-permission)
// Fields: GUESS(low); stand-ins for offsets observed on the target
#pragma once
#include <cstdint>

class NiPSysFieldModifier
{
public:
    NiPSysFieldModifier();
    virtual ~NiPSysFieldModifier();
    std::uint8_t baseState[0x48];
};
class NiPSysTurbulenceFieldModifier : public NiPSysFieldModifier
{
public:
    NiPSysTurbulenceFieldModifier();
    float frequency;
    float interval;
    float lastTime;
};
