// Exposure detail: (community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; labelled declarations and pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// NiPSysResetOnLoopCtlr, NiPSysResetOnLoopCtlr::Update, NiTimeController, NiUpdateData: CRASHLOGGER_PDB(59818@2026.10.24)
// m_fLastScaledTime: SYMBOLS(fo4-pdb)
// NiControllerVTable: STANDIN OBSERVED

#pragma once
#include <cstdint>
#include <cstddef>
// NiParticleSystem, resetSystem, modifierList: CRASHLOGGER_PDB(59818@2026.10.24)
// NiParticlesPrefix, NiControllerObject, particleStorage: STANDIN OBSERVED
struct NiParticlesPrefix { std::uint8_t particleStorage[0x168]; };
struct NiParticleSystem : NiParticlesPrefix
{
    void* modifierList[3];
    float unk180, unk184, unk188, lastUpdate;
    bool resetSystem;
};
struct NiTimeController;
struct NiControllerVTable
{
    void* precedingSlots[43];
    float (*computeScaledTime)(NiTimeController*, float);
};
struct NiUpdateData { float time; std::uint32_t flags; };
struct NiControllerObject
{
    NiControllerVTable* vtable;
    std::uint32_t refCount;
};
struct NiTimeController : NiControllerObject
{
    std::uint16_t flags;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    float startTime;
    float lastTime;
    float weightedLastTime;
    float scaledTime;
    std::uint32_t unknown34;
    NiParticleSystem* target;
    NiTimeController* nextController;
};
struct NiPSysResetOnLoopCtlr : NiTimeController
{
    void Update(NiUpdateData& data);
    float m_fLastScaledTime;
};
static_assert(offsetof(NiPSysResetOnLoopCtlr, m_fLastScaledTime) == 0x48, "last scaled time offset");
