// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x10b2590, 89 bytes: BhkTriangleShape scalar deleting destructor; the inline BhkTriangleShape destructor releases the Havok object and drops the instance count, then calls the out-of-line bhkConvexShape destructor.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectrefr_o2_variant.cpp:533
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x10b2590 ??_GBhkTriangleShape@@UEAAPEAXI@Z
#include "BhkTriangleShape_10b2590.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
BhkTriangleShape::BhkTriangleShape()
{
}
