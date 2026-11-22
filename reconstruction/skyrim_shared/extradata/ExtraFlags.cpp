// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names from the cited community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18b200 ExtraFlags::Function18b200
// Adapted bodies: none
// Function18b200, flags, FlagsCompare: GUESS(low)
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraFlags: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "ExtraFlags.h"

// GUESS(low): the four-argument helper tail-called by the compared body, bound by position.
extern bool FlagsCompare(ExtraFlags* a_other, const std::uint8_t* a_flags,
                         std::uint32_t a_first, std::uint32_t a_second);

bool ExtraFlags::Function18b200(ExtraFlags* a_other)
{
    const std::uint32_t count = 4;
    return FlagsCompare(a_other, flags, count, count);
}
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraFlags::GetType() const
{
    return 0xa0;
}
