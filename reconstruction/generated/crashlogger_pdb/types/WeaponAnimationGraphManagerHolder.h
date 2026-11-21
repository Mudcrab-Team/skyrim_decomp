// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WeaponAnimationGraphManagerHolder; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f.h"
#include "IAnimationGraphManagerHolder_f623b5a9.h"
struct WeaponAnimationGraphManagerHolder {
    IAnimationGraphManagerHolder_f623b5a9 _base;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
    BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f animationGraphManager;
};
static_assert(sizeof(WeaponAnimationGraphManagerHolder) == 24, "WeaponAnimationGraphManagerHolder layout differs from the PDB");
