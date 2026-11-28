// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xfa64c0 NiPSysAgeDeathModifier::CopyMembers
#include "NiPSysAgeDeathModifier_fa64c0.h"

// Copy base modifier state and the spawn-on-death flag to the destination clone.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void NiPSysAgeDeathModifier::CopyMembers(NiPSysAgeDeathModifier* a_dest, NiCloningProcess& a_process)
{
    NiPSysModifier::CopyMembers(a_dest, a_process);
    a_dest->spawnOnDeath = spawnOnDeath;
}
