// Source exposure: mixed (local binary analysis and public names).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// TESPackage: EXE_RTTI
// TESPackage::GetRefCount, TESPackage::GetObjectTypeName, TESPackage::~TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// objectType, unknown20, unknown25: GUESS(low); measured from the listings, names invented
#pragma once
#include <cstdint>
#include "../../skyrim_shared/forms/TESForm.h"
class TESPackage : public TESForm
{
public:
    TESPackage();
    // IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    virtual std::uint8_t IsPackageOwner() const;
    virtual std::uint32_t GetRefCount() const;
    virtual const char* GetObjectTypeName() const;
    virtual ~TESPackage();

private:
    // unknown20: GUESS(low); padding from the base end to the field at 0x24
    std::uint8_t unknown20[0x4];
    // objectType: GUESS(low); byte at 0x24, sign-extended and used as the table index
    std::int8_t objectType;
    // unknown25: GUESS(low); padding from 0x25 to 0xDB
    std::uint8_t unknown25[0xb7];
    // refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); dword at 0xDC
    std::uint32_t refCount;
};
static_assert(sizeof(TESPackage) == 0xe0, "TESPackage size");
