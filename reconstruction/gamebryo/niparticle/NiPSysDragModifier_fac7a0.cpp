// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xfac7a0 NiPSysDragModifier::CopyMembers
#include "NiPSysDragModifier_fac7a0.h"

// Copy base modifier state and all six drag parameters to the destination clone.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void NiPSysDragModifier::CopyMembers(NiPSysDragModifier* a_dest, NiCloningProcess& a_process)
{
    NiPSysModifier::CopyMembers(a_dest, a_process);
    a_dest->dragAxisX = dragAxisX;
    a_dest->dragAxisY = dragAxisY;
    a_dest->dragAxisZ = dragAxisZ;
    a_dest->percentage = percentage;
    a_dest->range = range;
    a_dest->rangeFalloff = rangeFalloff;
}
