// Code origin: hand-written from the local listings; names and declarations from the community header named in NiParticles.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xf055a0 NiParticles::AsParticlesGeom
// 0xf05220 NiParticles::RegisterStreamables
#include "NiParticles.h"

NiParticles* NiParticles::AsParticlesGeom()
{
    return this;
}

bool NiParticles::RegisterStreamables(NiStream& a_stream)
{
    particleData->RegisterStreamables(a_stream);
    return BSGeometry::RegisterStreamables(a_stream);
}
