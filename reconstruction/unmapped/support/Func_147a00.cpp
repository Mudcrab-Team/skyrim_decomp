// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase147a00::~MapBase147a00 and Func_147a00::~Func_147a00, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x147a00 Func_147a00::dtor_deleting
// CI hash: 0x147a00 ??_GFunc_147a00@@UEAAPEAXI@Z
#include "Func_147a00.h"

// PDB: the CrashLogger PDB name is NiTMap<char const*, Setting*>::~NiTMap; the stand-in name here is kept.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Func_147a00::Func_147a00() = default;
