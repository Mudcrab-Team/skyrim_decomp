// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x29e620 Obj29e620::~Obj29e620
// Adapted bodies: none
#include "Obj29e620.h"

// Runs object cleanup before chaining to the base destructor.
Obj29e620::~Obj29e620()
{
    Cleanup();
}
