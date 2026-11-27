// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataAmbush.cpp:40
// TESAmbushPackageData, TESAmbushPackageData::Compare, PackageLocation, PackageLocation::Compare: SIBLING(fo4-private@1b765c70, author-permission)
// TESAmbushPackageData::pAmbushLocation: GUESS(medium); name from the sibling Compare body
// TESPackageData, TESPackageData::Compare: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class PackageLocation
{
public:
    bool Compare(PackageLocation* a_other);
};

class TESPackageData
{
public:
    virtual ~TESPackageData();  // 00
    virtual bool Compare(TESPackageData* a_other);
};

class TESAmbushPackageData : public TESPackageData
{
public:
    bool Compare(TESPackageData* a_other) override;

    PackageLocation* pAmbushLocation;  // 08
};
