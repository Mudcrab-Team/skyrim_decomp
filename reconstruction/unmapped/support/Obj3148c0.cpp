// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj3148c0Base::~Obj3148c0Base and Obj3148c0::~Obj3148c0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x3148c0 Obj3148c0::~Obj3148c0
#include "Obj3148c0.h"

// PDB: the CrashLogger PDB name is NiTPointerMap<unsigned int, BSSimpleList<TESObjectREFR*>*>::~NiTPointerMap; the stand-in name here is kept.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Obj3148c0::Obj3148c0()
{
}
