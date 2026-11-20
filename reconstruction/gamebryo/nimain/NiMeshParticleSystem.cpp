// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf9eb30 NiMeshParticleSystem::~NiMeshParticleSystem
// Adapted bodies: none
#include "NiMeshParticleSystem.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiMeshParticleSystem::NiMeshParticleSystem()
{
}

NiMeshParticleSystem::~NiMeshParticleSystem()
{
}
