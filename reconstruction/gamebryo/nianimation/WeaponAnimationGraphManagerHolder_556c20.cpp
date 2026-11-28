// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// WeaponAnimationGraphManagerHolder, WeaponAnimationGraphManagerHolder::SetAnimationGraphManagerImpl: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x556c20 WeaponAnimationGraphManagerHolder::SetAnimationGraphManagerImpl
#include "WeaponAnimationGraphManagerHolder_556c20.h"

// Replaces the stored animation graph manager smart pointer.
bool WeaponAnimationGraphManagerHolder::SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_in)
{
    animationGraphManager = a_in;
    return true;
}
