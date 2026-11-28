// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: BSTSmartPointer::~BSTSmartPointer, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// WeaponAnimationGraphManagerHolder: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x5572c0 WeaponAnimationGraphManagerHolder::dtor_deleting
// CI hash: 0x5572c0 ??_GWeaponAnimationGraphManagerHolder@@UEAAPEAXI@Z
#include "WeaponAnimationGraphManagerHolder_5572c0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
WeaponAnimationGraphManagerHolder::WeaponAnimationGraphManagerHolder()
{
}

// Releases the animation graph manager pointer and destroys the base holder.
WeaponAnimationGraphManagerHolder::~WeaponAnimationGraphManagerHolder()
{
}
