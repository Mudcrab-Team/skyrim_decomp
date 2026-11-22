// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: names and declarations from community headers; the function body is written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xf05630 NiParticles::Functionf05630
// Adapted bodies: none
// NiParticles::Functionf05630: GUESS(low)
// Code origin: hand-written from the local listings; names and declarations from the community header named in NiParticles.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
#include "NiParticles.h"

#include <intrin.h>

// gParticleCount, Functionf05630: STANDIN GUESS(low); the counter is a global at the observed address.
extern volatile long gParticleCount;

void NiParticles::Functionf05630(std::uint32_t a_delta)
{
    if (!a_delta) {
        return;
    }
    long current;
    do {
        current = gParticleCount;
    } while (_InterlockedCompareExchange(&gParticleCount, current + static_cast<long>(a_delta), current) != current);
}

NiParticles* NiParticles::AsParticlesGeom()
{
    return this;
}

bool NiParticles::RegisterStreamables(NiStream& a_stream)
{
    particleData->RegisterStreamables(a_stream);
    return BSGeometry::RegisterStreamables(a_stream);
}
