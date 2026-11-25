// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0xf409d0, 102 bytes: NiOBBNode scalar deleting destructor; the inline destructor deletes two owned child objects.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xf409d0 ??_GNiOBBNode@@UEAAPEAXI@Z
#include "NiOBBNode_f409d0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
NiOBBNode::NiOBBNode()
{
}
