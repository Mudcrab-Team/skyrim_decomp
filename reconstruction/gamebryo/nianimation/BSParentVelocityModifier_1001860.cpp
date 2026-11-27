// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSParentVelocityModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSParentVelocityModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x1001860 BSParentVelocityModifier::CopyMembers
#include "BSParentVelocityModifier_1001860.h"

// Copy the base particle modifier and damping factor to the destination instance.
void BSParentVelocityModifier::CopyMembers(BSParentVelocityModifier* a_dest, void* a_process)
{
    NiPSysModifier::CopyMembers(a_dest, a_process);
    a_dest->damping = damping;
}
