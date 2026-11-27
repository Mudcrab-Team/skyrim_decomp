// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x1444d0, 62 bytes: LoadOrderEntry_CC scalar deleting destructor; the inline destructor chains to the out-of-line LoadOrderEntry destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x1444d0 ??_GLoadOrderEntry_CC@@UEAAPEAXI@Z
#include "LoadOrderEntry_CC_1444d0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
LoadOrderEntry_CC::LoadOrderEntry_CC()
{
}
