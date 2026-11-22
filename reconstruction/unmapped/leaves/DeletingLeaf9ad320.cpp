// Source exposure: mixed (binary-analysis of the pinned image; minimal stand-in).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original stand-in from the pinned image listing; no external body reused.
// 0x9ad320 DeletingLeaf9ad320::~DeletingLeaf9ad320
// Adapted bodies: none
#include "DeletingLeaf9ad320.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
DeletingLeaf9ad320::DeletingLeaf9ad320()
{
}
