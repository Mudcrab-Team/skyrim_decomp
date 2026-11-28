// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xcf8ed0 GMemoryHeap::dtor
#include "GMemoryHeap_cf8ed0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
GMemoryHeap::GMemoryHeap()
{
}

// Destroy GMemoryHeap and its internal lock member.
GMemoryHeap::~GMemoryHeap()
{
}
