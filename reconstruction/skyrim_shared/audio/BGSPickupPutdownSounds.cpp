// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned image and labelled declarations.; Written for this reconstruction from the listing: the target initialises the object and returns this, so it is modelled as placement construction through the constructor.
// Adapted bodies: none.
// 0x1db710 Leaf1db710::Invoke
// 0x1db6f0 BGSPickupPutdownSounds::InitializeDataComponent
// 0x1db880 BGSPickupPutdownSounds::~BGSPickupPutdownSounds
// SPDX-License-Identifier: CC0-1.0
// 0x1db800 BGSPickupPutdownSounds::GetPickupSound
// 0x1db840 BGSPickupPutdownSounds::GetPutdownSound
// GetPickupSound, GetPutdownSound: GUESS(low)
// 0x1db6b0 BGSPickupPutdownSounds::Function1db6b0
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BGSPickupPutdownSounds.h"

#include <new>

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
// Not compared: the constructor stores the vftable, then zeroes both sound pointers.
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

// Function1db6b0: GUESS(low); placement construction of this object through its constructor, returning this.
BGSPickupPutdownSounds* BGSPickupPutdownSounds::Function1db6b0()
{
    return new (this) BGSPickupPutdownSounds();
}
