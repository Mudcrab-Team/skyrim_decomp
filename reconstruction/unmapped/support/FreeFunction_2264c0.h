// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IsKindOfParticleSystem, treated as adapted: shaped like NiRTTI::IsKindOf in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// SPDX-License-Identifier: CC0-1.0
// ResetParticleSystems: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRTTI2264c0, NiAVObject2264c0, NiParticleSystem2264c0, GetRTTI, reset, gParticleSystemRTTI2264c0: GUESS(low)
#pragma once

#include <cstdint>

struct NiRTTI2264c0
{
    const char* name;
    const NiRTTI2264c0* base;
};

extern NiRTTI2264c0 gParticleSystemRTTI2264c0;

class NiAVObject2264c0
{
public:
    virtual ~NiAVObject2264c0();
    virtual void Unk_01();
    virtual const NiRTTI2264c0* GetRTTI() const;
};

class NiParticleSystem2264c0 : public NiAVObject2264c0
{
public:
    std::uint8_t unk08[0x188];  // 008
    bool reset;                 // 190
};

std::uint32_t ResetParticleSystems(NiAVObject2264c0* obj);
