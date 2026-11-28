// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase216240::~NiTMapBase216240, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// 0x216240 NiTMapBase216240::~NiTMapBase216240
#include "NiTMapBase216240.h"

// PDB: the CrashLogger PDB name is NiTMapBase<NiTexture* to TEX_USER_DATA*>::~NiTMapBase; the stand-in name here is kept.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTMapBase216240::NiTMapBase216240()
{
}

// Clear all map entries and free the hash table array.
NiTMapBase216240::~NiTMapBase216240()
{
    RemoveAll();
    NiFree216240(hashTable);
}
