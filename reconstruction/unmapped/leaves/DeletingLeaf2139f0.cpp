// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: names from the inventory and the pinned image listing; the destructor body is written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x2139f0 DeletingLeaf2139f0::~DeletingLeaf2139f0
// Adapted bodies: none
#include "DeletingLeaf2139f0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
DeletingLeaf2139f0::DeletingLeaf2139f0()
{
}

// The complete destructor is inline so the emitted deleting destructor stores the vptr
// before the conditional sized delete, as the listing shows.
DeletingLeaf2139f0::~DeletingLeaf2139f0()
{
}
