// Source exposure: mixed (binary-analysis of the pinned image; minimal stand-in).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original stand-in from the pinned image listing; no external body reused.
// 0x11392c0 DeletingLeaf11392c0::scalar deleting destructor
// Adapted bodies: none
#include "DeletingLeaf11392c0.h"

// Not compared: defining the constructor makes the compiler emit the vftable beside which
// the compared scalar deleting destructor (cookbook rule 14) is generated.
DeletingLeaf11392c0::DeletingLeaf11392c0()
{
}
