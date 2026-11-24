// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xffbcf0 BSMasterParticleSystem::IsMasterParticleSystem
// Adapted bodies: none
#include "BSMasterParticleSystem_ffbcf0.h"

namespace
{
    // IsExactKindOf: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); a free null-checking form of the sibling's member test
    inline bool IsExactKindOf(const NiRTTI* a_rtti, NiTimeController* a_object)
    {
        return a_object && a_object->GetRTTI() == a_rtti;
    }
}

bool BSMasterParticleSystem::IsMasterParticleSystem(NiParticles* a_particles)
{
    for (NiTimeController* controller = a_particles->controllers; controller; controller = controller->next) {
        if (IsExactKindOf(&g_masterParticleControllerRTTI, controller)) {
            return true;
        }
    }
    return false;
}
