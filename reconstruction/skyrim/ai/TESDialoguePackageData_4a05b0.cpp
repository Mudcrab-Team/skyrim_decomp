// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x4a05b0, 87 bytes: TESDialoguePackageData scalar deleting destructor; the inline destructor deletes the owned object at 0x18, then the inline TESPackageData destructor resets the vftable.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x4a05b0 ??_GTESDialoguePackageData@@UEAAPEAXI@Z
#include "TESDialoguePackageData_4a05b0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
TESDialoguePackageData::TESDialoguePackageData()
{
}
