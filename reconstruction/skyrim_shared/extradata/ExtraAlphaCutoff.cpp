// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template; IsNotEqual original from the listing.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAlphaCutoff: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x18b150 ExtraAlphaCutoff::GetType
// 0x18b130 ExtraAlphaCutoff::IsNotEqual
#include "ExtraAlphaCutoff.h"

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraAlphaCutoff::GetType() const
{
    return 0x9a;
}

bool ExtraAlphaCutoff::IsNotEqual(const BSExtraData* a_rhs) const
{
    const auto* rhs = static_cast<const ExtraAlphaCutoff*>(a_rhs);
    return rhs->unk10 != unk10 || rhs->unk11 != unk11;
}
