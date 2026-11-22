// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: names from the inventory and the pinned image listing; the destructor body is written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x216300 DeletingLeaf216300::~DeletingLeaf216300
// Adapted bodies: none
#include "DeletingLeaf216300.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
DeletingLeaf216300::DeletingLeaf216300()
{
}

// The complete destructor is inline so the emitted deleting destructor stores the vptr
// before the conditional sized delete, as the listing shows.
DeletingLeaf216300::~DeletingLeaf216300()
{
}
