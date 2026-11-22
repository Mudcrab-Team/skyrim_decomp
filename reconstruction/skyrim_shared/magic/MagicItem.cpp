// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x150310 MagicItem::IsValid
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// MagicItem: EXE_RTTI
// IsMagicItem: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "MagicItem.h"
// IsMagicItem: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t MagicItem::IsMagicItem() const
{
    return 0x1;
}

// IsValid: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
bool MagicItem::IsValid() const
{
    std::uint32_t spellType = GetSpellType();
    return spellType == 1 || spellType == 4 || spellType == 10;
}
