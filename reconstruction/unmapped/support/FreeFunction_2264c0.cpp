// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IsKindOfParticleSystem, treated as adapted: shaped like NiRTTI::IsKindOf in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// SPDX-License-Identifier: CC0-1.0
// 0x2264c0 ResetParticleSystems
#include "FreeFunction_2264c0.h"

namespace
{
inline bool IsKindOfParticleSystem(const NiAVObject2264c0* obj)
{
    if (!obj)
    {
        return false;
    }
    for (const NiRTTI2264c0* rtti = obj->GetRTTI(); rtti; rtti = rtti->base)
    {
        if (rtti == &gParticleSystemRTTI2264c0)
        {
            return true;
        }
    }
    return false;
}
}

// Mark a particle system node to reset when the object derives from NiParticleSystem.
std::uint32_t ResetParticleSystems(NiAVObject2264c0* obj)
{
    if (IsKindOfParticleSystem(obj))
    {
        static_cast<NiParticleSystem2264c0*>(obj)->reset = true;
    }
    return 0;
}
