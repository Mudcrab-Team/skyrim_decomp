// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d1500Base::~Obj2d1500Base and Obj2d1500::~Obj2d1500, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x2d1500 Obj2d1500::~Obj2d1500
#include "Obj2d1500.h"

// Guess: clear hash-map entries and release the base table storage.
Obj2d1500::~Obj2d1500()
{
    RemoveAll();
}
