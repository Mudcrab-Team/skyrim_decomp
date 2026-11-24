// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x1002d80, 62 bytes: BSPSysStripUpdateModifier scalar deleting destructor; the inline destructors chain to the out-of-line NiPSysModifier destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x1002d80 ??_GBSPSysStripUpdateModifier@@UEAAPEAXI@Z
#include "BSPSysStripUpdateModifier_1002d80.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
BSPSysStripUpdateModifier::BSPSysStripUpdateModifier()
{
}
