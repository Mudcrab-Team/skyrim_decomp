// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x4e35f0, 62 bytes: PathingRequest scalar deleting destructor; the inline destructor chains to the out-of-line BSPathingRequest destructor.
// Adapted bodies: none
// CI hash: 0x4e35f0 ??_GPathingRequest@@UEAAPEAXI@Z
#include "PathingRequest_4e35f0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
PathingRequest::PathingRequest()
{
}
