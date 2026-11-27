// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf055e0 NiParticles::UpdateGlobalEmissionScale
#include "NiParticles_f055e0.h"
#include <intrin.h>

void NiParticles::UpdateGlobalEmissionScale(std::uint32_t limit)
{
    // Reset the shared particle count atomically.
    const auto updated = static_cast<std::uint32_t>(_InterlockedExchange(&gUpdatedParticleCount, 0));
    if (updated > limit) {
        const float ratio = static_cast<float>(limit) / static_cast<float>(updated);
        gParticleEmissionScale = ratio * ratio;
    } else {
        gParticleEmissionScale = 1.0f;
    }
}
