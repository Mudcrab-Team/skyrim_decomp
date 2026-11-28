// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_147940::~Func_147940, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// 0x147940 Func_147940::dtor_deleting
// CI hash: 0x147940 ??_GFunc_147940@@UEAAPEAXI@Z
#include "Func_147940.h"

// PDB: the CrashLogger PDB name is NiTMapBase<..., char const*, Setting*>::~NiTMapBase; the stand-in name here is kept.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Func_147940::Func_147940() = default;
