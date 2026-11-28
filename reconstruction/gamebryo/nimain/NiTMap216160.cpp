// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase216160::~NiTMapBase216160 and NiTMap216160::~NiTMap216160, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x216160 NiTMap216160::~NiTMap216160
#include "NiTMap216160.h"

// PDB: the CrashLogger PDB name is NiTMap<NiTexture*, TEX_USER_DATA*>::~NiTMap; the stand-in name here is kept.
// Clear all map entries and free the hash table array.
NiTMapBase216160::~NiTMapBase216160()
{
    RemoveAll();
    NiFree216160(hashTable);
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTMap216160::NiTMap216160()
{
}

// Clear derived map entries before base teardown.
NiTMap216160::~NiTMap216160()
{
    RemoveAll();
}
