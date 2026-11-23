// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x32a830 BGSSoundDescriptorForm::Function32a830
// Adapted bodies: none
#include "BGSSoundDescriptorForm_32a830.h"

std::uint8_t BGSSoundDescriptorForm::Function32a830(SoundDescriptorOut* a_out) const
{
    std::uint8_t result = 0;
    if (inner) {
        result = inner->GetFlag();
        // the owning form's id lives in the enclosing object, before this subobject
        a_out->formID = *reinterpret_cast<const std::uint32_t*>(reinterpret_cast<const std::uint8_t*>(this) - 0xC);
    }
    return result;
}
