// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned image and labelled declarations.
// Adapted bodies: none.
// 0x1db710 Leaf1db710::Invoke
// 0x1db6f0 BGSPickupPutdownSounds::InitializeDataComponent
// 0x1db880 BGSPickupPutdownSounds::~BGSPickupPutdownSounds
// SPDX-License-Identifier: CC0-1.0
// 0x1db800 BGSPickupPutdownSounds::GetPickupSound
// 0x1db840 BGSPickupPutdownSounds::GetPutdownSound
// GetPickupSound, GetPutdownSound: GUESS(low)
#include "BGSPickupPutdownSounds.h"

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

// Resolve the pickup sound component on the supplied form.
BGSSoundDescriptorForm* BGSPickupPutdownSounds::GetPickupSound(TESForm* a_form)
{
    auto* sounds = dynamic_cast<BGSPickupPutdownSounds*>(a_form);
    if (sounds) {
        return sounds->field08;
    }
    return nullptr;
}

// Resolve the putdown sound component on the supplied form.
BGSSoundDescriptorForm* BGSPickupPutdownSounds::GetPutdownSound(TESForm* a_form)
{
    auto* sounds = dynamic_cast<BGSPickupPutdownSounds*>(a_form);
    if (sounds) {
        return sounds->field10;
    }
    return nullptr;
}
