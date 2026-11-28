// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase2161d0::~NiTMapBase2161d0 and NiTMap2161d0::~NiTMap2161d0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x2161d0 NiTMap2161d0::~NiTMap2161d0
#include "NiTMap2161d0.h"

// PDB: the CrashLogger PDB name is NiTMap<NiTexture*, bool>::~NiTMap; the stand-in name here is kept.
// Clear all map entries and free the hash table array.
NiTMapBase2161d0::~NiTMapBase2161d0()
{
    RemoveAll();
    NiFree2161d0(hashTable);
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTMap2161d0::NiTMap2161d0()
{
}

// Clear derived map entries before base teardown.
NiTMap2161d0::~NiTMap2161d0()
{
    RemoveAll();
}
