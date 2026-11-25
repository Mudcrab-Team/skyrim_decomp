// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiParticles, UpdateGlobalEmissionScale: SIBLING(fo4-private@1b765c70, author-permission)
// Globals: GUESS(low); stand-ins for target storage
#pragma once
#include <cstdint>

// volatile: the target resets this counter atomically.
extern volatile long gUpdatedParticleCount;
extern float gParticleEmissionScale;
struct NiParticles
{
    static void UpdateGlobalEmissionScale(std::uint32_t limit);
};
