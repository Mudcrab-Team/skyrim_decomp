// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template; Function189930 original from the listing.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// ExtraTextDisplayData: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function189930, ParseQuestText: GUESS(low)
// 0x189e90 ExtraTextDisplayData::GetType
// 0x189930 ExtraTextDisplayData::Function189930
#include "ExtraTextDisplayData.h"

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraTextDisplayData::GetType() const
{
    return 0x99;
}

BSString* ExtraTextDisplayData::Function189930(BSString* a_text) const
{
    if (ownerQuest) {
        return ParseQuestText(a_text, ownerQuest, ownerInstance);
    }
    return a_text;
}
