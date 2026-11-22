// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: SKELETON_TODO_CODE_ORIGIN (state the actual origin and any adaptation)
// SPDX-License-Identifier: CC0-1.0
// 0x18b130 ExtraAlphaCutoff::Function18b130
// Adapted bodies: SKELETON_TODO_ORIGIN (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraAlphaCutoff: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "ExtraAlphaCutoff.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraAlphaCutoff::GetType() const
{
    return 0x9a;
}

bool ExtraAlphaCutoff::Function18b130(const ExtraAlphaCutoff* a_other) const
{
    if (a_other->field10 != field10) return true;
    if (a_other->field11 != field11) return true;
    return false;
}
