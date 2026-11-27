// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1f8b50 BGSParticleArrayAttach__CollectEmitterPolicy::Func2_1401A6F20
// Adapted bodies: none
#include "BGSParticleArrayAttach_1f8b50.h"

// Clears every collected emitter pointer and releases the backing array.
void BGSParticleArrayAttach::CollectEmitterPolicy::Func2_1401A6F20()
{
    for (std::uint32_t i = 0; i < emitters.size; ++i) {
        emitters.data[i] = nullptr;
    }
    emitters.Clear();
}
