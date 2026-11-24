// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x11d2b50, 62 bytes: CheckStoppedMovingFunctor scalar deleting destructor; the inline destructor chains to the out-of-line ICheckEndReachedFunctor destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x11d2b50 ??_GCheckStoppedMovingFunctor@@UEAAPEAXI@Z
#include "CheckStoppedMovingFunctor_11d2b50.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
CheckStoppedMovingFunctor::CheckStoppedMovingFunctor()
{
}
