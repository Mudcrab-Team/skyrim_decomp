// Source exposure: mixed (binary-analysis of the pinned image; minimal stand-in).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original stand-in from the pinned image listing; no external body reused.
// 0x10d3720 DeletingLeaf10d3720::~DeletingLeaf10d3720
// Adapted bodies: none
#include "DeletingLeaf10d3720.h"

// Forces emission of the vftable and, beside it, the compared deleting destructor.
static DeletingLeaf10d3720 object;
