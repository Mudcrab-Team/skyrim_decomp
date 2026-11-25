// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations. Stamped as a twin of matched 0x44e660 (skyrim/ai/BGSPackageDataBool): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// IPackageData: STANDIN EXE_RTTI
// BSString, BGSLoadFormBuffer, BGSSaveGameBuffer, TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the compared code calls are declared
// BGSNamedPackageData_VIPackageData::LoadPackage: GUESS(low); the base load the image calls first, the name is invented
// Owner44d730: GUESS(low) STANDIN
// GetDataAsString, Unk_07, LoadBuffer, LoadPackage, BGSNamedPackageData_VIPackageData: GUESS(low) STANDIN
#pragma once
#include "BGSPackageDataBool.h"

class Owner44d730 : public BGSNamedPackageData_VIPackageData
{
public:
    virtual std::uint8_t Unk_05() const;
    Owner44d730();
    virtual bool GetDataAsString(BSString* a_dst) const;
    virtual void Unk_07(BGSSaveGameBuffer* a_buf);
    virtual ~Owner44d730();
    virtual void LoadBuffer(BGSLoadFormBuffer* a_buf);
    virtual void Assign(IPackageData* a_other);
    virtual void LoadPackage(TESFile* a_mod);
    virtual bool IsNotEqual(IPackageData* a_other) const;
};
static_assert(sizeof(Owner44d730) == 0x10, "Owner44d730 size");
