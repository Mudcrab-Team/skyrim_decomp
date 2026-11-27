// Near miss: 26.0 alignment distance | control-flow
// Exposure detail: (community declarations and the pinned image).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiMeshParticleSystem, NiMeshParticleSystem::UpdateWorldData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAVObject, NiParticleSystem, NiTransform, NiUpdateData, local, world, particleData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MeshParticleData, target, unknownB0, unknown30, unknown3C, unknownB0to158, Slot: GUESS(low)
// Adapted bodies: none
// 0xf9e8d0 NiMeshParticleSystem::UpdateWorldData

#include "include/f9e8d0/NiMeshParticleSystem_f9e8d0.h"
#include <cmath>

void NiMeshParticleSystem::UpdateWorldData(NiUpdateData* data)
{
    NiParticleSystem::UpdateWorldData(data);
    NiAVObject* mesh = particleData->target;
    mesh->local.rotate[0] = world.rotate[0];
    mesh->local.rotate[1] = world.rotate[1];
    mesh->local.rotate[2] = world.rotate[2];
    mesh->local.rotate[3] = world.rotate[3];
    mesh->local.rotate[4] = world.rotate[4];
    mesh->local.rotate[5] = world.rotate[5];
    mesh->local.rotate[6] = world.rotate[6];
    mesh->local.rotate[7] = world.rotate[7];
    mesh->local.rotate[8] = world.rotate[8];
    mesh->local.translate[0] = world.translate[0];
    mesh->local.translate[1] = world.translate[1];
    mesh->local.translate[2] = world.translate[2];
    mesh->local.scale = std::fabs(world.scale);
    mesh->UpdateWorldData(data);
}
