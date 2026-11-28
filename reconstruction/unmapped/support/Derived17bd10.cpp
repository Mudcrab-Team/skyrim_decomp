// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x17bd10 Derived17bd10::~Derived17bd10
// Adapted bodies: none
#include "Derived17bd10.h"

// Releases the owned character allocation before resetting the base vtable.
Derived17bd10::~Derived17bd10()
{
    delete buffer;
}
