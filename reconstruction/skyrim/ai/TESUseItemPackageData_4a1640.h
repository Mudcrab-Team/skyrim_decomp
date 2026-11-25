// Source exposure: mixed (community headers; the pinned image listing).
// TESUseItemPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PackageDataPayload, TESUseItemPackageData::payload: GUESS(low)
#pragma once

class TESPackageData
{
public:
    virtual ~TESPackageData() {}
};

class PackageDataPayload
{
public:
    virtual ~PackageDataPayload() {}
};

class TESUseItemPackageData : public TESPackageData
{
public:
    ~TESUseItemPackageData() override;

    PackageDataPayload* payload;  // 08
};
static_assert(sizeof(TESUseItemPackageData) == 0x10, "TESUseItemPackageData size");
