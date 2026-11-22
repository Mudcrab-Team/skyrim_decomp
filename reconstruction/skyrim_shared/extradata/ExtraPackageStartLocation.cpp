// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template; IsNotEqual original from the listing.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPackageStartLocation: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x181960 ExtraPackageStartLocation::GetType
// 0x181930 ExtraPackageStartLocation::IsNotEqual
#include "ExtraPackageStartLocation.h"

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraPackageStartLocation::GetType() const
{
    return 0x18;
}

#include <cstring>

bool ExtraPackageStartLocation::IsNotEqual(const BSExtraData* a_rhs) const
{
    const auto* rhs = static_cast<const ExtraPackageStartLocation*>(a_rhs);
    return std::memcmp(&worldLoc, &rhs->worldLoc, sizeof(worldLoc)) != 0;
}
