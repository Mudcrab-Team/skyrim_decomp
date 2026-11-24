// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x17dcf0, 66 bytes: ExtraTextDisplayData scalar deleting destructor; the implicit destructor releases the display name, then the inline BSExtraData destructor resets the vftable.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x17dcf0 ??_GExtraTextDisplayData@@UEAAPEAXI@Z
#include "ExtraTextDisplayData_17dcf0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
ExtraTextDisplayData::ExtraTextDisplayData()
{
}
