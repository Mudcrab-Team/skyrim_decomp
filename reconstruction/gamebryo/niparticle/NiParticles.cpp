// Code origin: hand-written from the local listings; names and declarations from the community header named in NiParticles.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xf055a0 NiParticles::AsParticlesGeom
// 0xf05220 NiParticles::RegisterStreamables
// 0xf05630 NiParticles::AdjustParticleTotal
// 0xf05720 NiParticles::NiParticles
#include "NiParticles.h"

#include <intrin.h>

NiParticles* NiParticles::AsParticlesGeom()
{
    return this;
}

bool NiParticles::RegisterStreamables(NiStream& a_stream)
{
    particleData->RegisterStreamables(a_stream);
    return BSGeometry::RegisterStreamables(a_stream);
}

void NiParticles::AdjustParticleTotal(std::int32_t a_count)
{
    if (a_count) {
        long previous;
        do {
            previous = particleTotal;
            // retry until no other thread changed the total in between
        } while (_InterlockedCompareExchange(&particleTotal, previous + a_count, previous) != previous);
    }
}

NiParticles::NiParticles()
{
    particleData = nullptr;
    flags02() |= 0x8;
    unk160 = 0;
    vertexDesc = 0x0840200004000051;  // the vertex layout particles are drawn with
    type = 1;                         // particles
}
