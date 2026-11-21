// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing, community declarations and CrashLogger PDB names only
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1db710 Leaf1db710::Invoke
// 0x1db6f0 BGSPickupPutdownSounds::InitializeDataComponent
// 0x1db880 BGSPickupPutdownSounds::~BGSPickupPutdownSounds
// 0x1db6b0 BGSPickupPutdownSounds::BGSPickupPutdownSounds
// BGSPickupPutdownSounds::BGSPickupPutdownSounds: CRASHLOGGER_PDB(59818@2026.10.24)
#include "BGSPickupPutdownSounds.h"

BGSPickupPutdownSounds::BGSPickupPutdownSounds()
{
    field08 = 0;
    field10 = 0;
}

// ClearDataComponent: the listing is a bare return; there is no work to do.
void BGSPickupPutdownSounds::ClearDataComponent()
{
}

// InitializeDataComponent: both qwords are zeroed, in the same order as the listing.
void BGSPickupPutdownSounds::InitializeDataComponent()
{
    field08 = 0;
    field10 = 0;
}

// Compared as the scalar deleting destructor; the base destructor and vftable store are inlined by the
// compiler, so the body is empty.
BGSPickupPutdownSounds::~BGSPickupPutdownSounds()
{
}
