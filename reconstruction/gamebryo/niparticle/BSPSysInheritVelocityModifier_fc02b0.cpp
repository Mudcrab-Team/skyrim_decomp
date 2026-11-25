// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0xfc02b0, 62 bytes: BSPSysInheritVelocityModifier scalar deleting destructor; the inline destructor chains to the out-of-line NiPSysModifier destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xfc02b0 ??_GBSPSysInheritVelocityModifier@@UEAAPEAXI@Z
#include "BSPSysInheritVelocityModifier_fc02b0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
BSPSysInheritVelocityModifier::BSPSysInheritVelocityModifier()
{
}
