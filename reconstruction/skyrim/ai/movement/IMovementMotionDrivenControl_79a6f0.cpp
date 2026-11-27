// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x79a6f0, 62 bytes: IMovementMotionDrivenControl scalar deleting destructor; the inline destructors chain to the out-of-line IMovementInterface destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x79a6f0 ??_GIMovementMotionDrivenControl@@UEAAPEAXI@Z
#include "IMovementMotionDrivenControl_79a6f0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
IMovementMotionDrivenControl::IMovementMotionDrivenControl()
{
}
