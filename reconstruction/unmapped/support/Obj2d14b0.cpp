// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Base2d14b0::~Base2d14b0 and Obj2d14b0::~Obj2d14b0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// 0x2d14b0 Obj2d14b0::~Obj2d14b0
#include "Obj2d14b0.h"

// Clears entries before base destructor clears and frees the bucket array.
Obj2d14b0::~Obj2d14b0()
{
    Clear();
}
