// Source exposure: mixed (community headers; the pinned image listing).
// TESEatPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PackageDataPayload, TESEatPackageData::payload: GUESS(low)
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

class TESEatPackageData : public TESPackageData
{
public:
    ~TESEatPackageData() override;

    PackageDataPayload* payload;  // 08
};
static_assert(sizeof(TESEatPackageData) == 0x10, "TESEatPackageData size");
