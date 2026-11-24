// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x11d2cd0, 62 bytes: IMovementQueryPathFollowing scalar deleting destructor; the inline destructors chain to the out-of-line IMovementInterface destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x11d2cd0 ??_GIMovementQueryPathFollowing@@UEAAPEAXI@Z
#include "IMovementQueryPathFollowing_11d2cd0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
IMovementQueryPathFollowing::IMovementQueryPathFollowing()
{
}
