// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1c6840 Obj1c6840::~Obj1c6840
// Adapted bodies: none.
#include "Obj1c6840.h"

// Destroys the object and releases its held member.
Obj1c6840::~Obj1c6840()
{
    member08->Release();
}
