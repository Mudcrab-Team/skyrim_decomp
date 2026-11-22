// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names from the cited community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1db6b0 BGSPickupPutdownSounds::Function1db6b0
// Adapted bodies: none
// Function1db6b0, pickupVftable: GUESS(low)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "BGSPickupPutdownSounds.h"

// GUESS(low): the vftable the initializer installs, bound by position from the pack.
extern char pickupVftable[];

BGSPickupPutdownSounds* BGSPickupPutdownSounds::Function1db6b0()
{
    *reinterpret_cast<const void**>(this) = pickupVftable;
    field08 = 0;
    field10 = 0;
    return this;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSPickupPutdownSounds::BGSPickupPutdownSounds()
{
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
