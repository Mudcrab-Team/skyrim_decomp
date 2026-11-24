// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0x340570, 64 bytes: GetVMConditionalVariableValueFunc scalar deleting destructor; the member and base destructors stay out of line.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x340570 ??_GGetVMConditionalVariableValueFunc@@UEAAPEAXI@Z
#include "GetVMConditionalVariableValueFunc_340570.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
GetVMConditionalVariableValueFunc::GetVMConditionalVariableValueFunc()
{
}
