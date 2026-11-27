// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0xed09e0, 62 bytes: ArchiveRegistrationTaskData scalar deleting destructor; the inline destructor chains to the out-of-line base destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xed09e0 ??_GArchiveRegistrationTaskData@@UEAAPEAXI@Z
#include "ArchiveRegistrationTaskData_ed09e0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
ArchiveRegistrationTaskData::ArchiveRegistrationTaskData()
{
}
