// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x10ba8b0, 76 bytes: hkRagdollLimitsConstraintCinfo scalar deleting destructor; the inline hkConstraintCinfo destructor clears its constraint data; the non-polymorphic hkSerializableCinfo base has nothing to destroy.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x10ba8b0 ??_GhkRagdollLimitsConstraintCinfo@@UEAAPEAXI@Z
#include "hkRagdollLimitsConstraintCinfo_10ba8b0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
hkRagdollLimitsConstraintCinfo::hkRagdollLimitsConstraintCinfo()
{
}
