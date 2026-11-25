// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysSpawnModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// NiPSysModifier base size: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in types and fields: GUESS(low); remaining offsets observed on the target
#pragma once
#include <cstdint>

class SpawnModifierBase
{
public:
    SpawnModifierBase();
    virtual ~SpawnModifierBase();
    std::uint8_t state[0x28];
};
class SpawnLeaffb9890 : public SpawnModifierBase
{
public:
    SpawnLeaffb9890();
    std::uint16_t generations;
    float fraction;
    std::uint16_t minimum;
    std::uint16_t maximum;
    float speedVariance;
    float directionVariance;
    float lifetime;
    float lifetimeVariance;
};
