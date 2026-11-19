// Source exposure: mixed (local binary analysis and public names).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// Adapted bodies for the new functions: none; each body is written from its listing.
// TESPackageObjectTypeNames: GUESS(low); a table of pointers indexed by objectType, bound by address through bind-hints.json.
// TESPackage::TESPackage: GUESS(low); constructor name from the class name, body empty
// TESPackage::GetRefCount, TESPackage::GetObjectTypeName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x49e8e0 TESPackage::IsPackageOwner
// 0x49e8d0 TESPackage::GetRefCount
#include "TESPackage.h"

extern const char* const TESPackageObjectTypeNames[];

// Not compared: defined so that the compiler emits the vftable and the deleting destructor beside it.
TESPackage::TESPackage()
{
}

// IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t TESPackage::IsPackageOwner() const
{
    return 0x1;
}

std::uint32_t TESPackage::GetRefCount() const
{
    return refCount;
}

const char* TESPackage::GetObjectTypeName() const
{
    return TESPackageObjectTypeNames[objectType];
}
