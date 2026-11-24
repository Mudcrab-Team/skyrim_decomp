// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x145370, 62 bytes: ViewAllEntry scalar deleting destructor; the inline destructors chain to the out-of-line UI_element destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x145370 ??_GViewAllEntry@@UEAAPEAXI@Z
#include "ViewAllEntry_145370.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
ViewAllEntry::ViewAllEntry()
{
}
