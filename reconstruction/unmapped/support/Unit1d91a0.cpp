// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1d91a0 Unit1d91a0::~Unit1d91a0
// CI hash: 0x1d91a0 ??1Unit1d91a0@@UEAA@XZ
// Adapted bodies: none
#include "Unit1d91a0.h"

// Clears the embedded icon subobject before destroying it and the base component.
// guess: the CrashLogger PDB names the member destructor address TESTexture::ctor; the stand-in names are kept.
Unit1d91a0::~Unit1d91a0()
{
    icon.Clear();
}
