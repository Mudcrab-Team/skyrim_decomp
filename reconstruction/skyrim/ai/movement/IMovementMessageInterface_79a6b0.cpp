// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x79a6b0, 62 bytes: IMovementMessageInterface scalar deleting destructor; the inline destructor chains to the out-of-line IMovementInterface destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x79a6b0 ??_GIMovementMessageInterface@@UEAAPEAXI@Z
#include "IMovementMessageInterface_79a6b0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
IMovementMessageInterface::IMovementMessageInterface()
{
}
