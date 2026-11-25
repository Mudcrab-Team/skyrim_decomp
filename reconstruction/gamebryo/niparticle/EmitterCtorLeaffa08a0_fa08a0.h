// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysEmitter: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types, fields and global: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct EmitterColor { float red, green, blue, alpha; };
extern EmitterColor gEmitterColor;
class EmitterCtorBase
{
public:
    EmitterCtorBase();
    virtual ~EmitterCtorBase();
    std::uint8_t state[0x28];
};
class EmitterCtorLeaffa08a0 : public EmitterCtorBase
{
public:
    EmitterCtorLeaffa08a0();
    float remainder, speed, speedVariation, declination, declinationVariation, angle, angleVariation;
    EmitterColor color;
    float radius, radiusVariation, lifetime, lifetimeVariation, scale;
};
