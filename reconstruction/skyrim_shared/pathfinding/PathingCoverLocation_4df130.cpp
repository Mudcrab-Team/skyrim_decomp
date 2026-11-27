// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x4df130, 66 bytes: PathingCoverLocation scalar deleting destructor; the inline destructor resets the vftable, then the out-of-line non-virtual BSPathingLocation base destructor runs.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x4df130 ??_GPathingCoverLocation@@UEAAPEAXI@Z
#include "PathingCoverLocation_4df130.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
PathingCoverLocation::PathingCoverLocation()
{
}
