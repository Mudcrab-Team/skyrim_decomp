// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; compact declaration views of the observed classes
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticleSystem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); constructor, destructor and size only
// NiMeshParticleSystem, time, updateControllers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiMeshParticleSystem::NiMeshParticleSystem: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>
#include <cstddef>

class NiParticleSystem
{
public:
    NiParticleSystem();
    virtual ~NiParticleSystem();
    std::uint8_t baseState[0x190];
};
static_assert(sizeof(NiParticleSystem) == 0x198, "NiParticleSystem size");

class NiMeshParticleSystem : public NiParticleSystem
{
public:
    NiMeshParticleSystem();
    ~NiMeshParticleSystem() override;
    float time;
    bool updateControllers;
};
static_assert(offsetof(NiMeshParticleSystem, time) == 0x198, "time offset");
static_assert(offsetof(NiMeshParticleSystem, updateControllers) == 0x19C, "updateControllers offset");
