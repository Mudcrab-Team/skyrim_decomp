// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned image and labelled declarations. Stamped as a twin of matched 0x1db800 (skyrim_shared/audio/BGSPickupPutdownSounds): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x1dba20 Owner1dba20::Function1dba20
#include "Owner1dba20.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Owner1dba20::Owner1dba20()
{
}

// Resolve the pickup sound component on the supplied form.
BGSSoundDescriptorForm* Owner1dba20::Function1dba20(TESForm* a_form)
{
    auto* sounds = dynamic_cast<Owner1dba20*>(a_form);
    if (sounds) {
        return sounds->field08;
    }
    return nullptr;
}
