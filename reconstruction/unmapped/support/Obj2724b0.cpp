// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2724b0 Obj2724b0::~Obj2724b0
// Adapted bodies: none
#include "Obj2724b0.h"

// Runs cleanup before destroying secondary and primary bases.
Obj2724b0::~Obj2724b0()
{
    Cleanup();
}
