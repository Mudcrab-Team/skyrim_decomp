// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x10bbd00, 76 bytes: hkWheelConstraintCinfo scalar deleting destructor; the inline hkConstraintCinfo destructor clears its constraint data; the non-polymorphic hkSerializableCinfo base has nothing to destroy.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x10bbd00 ??_GhkWheelConstraintCinfo@@UEAAPEAXI@Z
#include "hkWheelConstraintCinfo_10bbd00.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
hkWheelConstraintCinfo::hkWheelConstraintCinfo()
{
}
