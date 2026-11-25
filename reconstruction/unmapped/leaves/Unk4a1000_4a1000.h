// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited siblings.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: Unk4a1000::~Unk4a1000 follows momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/packagedatafollow.cpp
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/packagedatafollow.cpp:68
// TESFollowPackageData::pStartLocation: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// Unk4a1000: GUESS(low); placeholder owner of this unit, the class is TESFollowPackageData
// TESFollowPackageData: CRASHLOGGER_PDB(59818@2026.10.24)
// PackageLocation, TESPackageData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk10: GUESS(low)
#pragma once

#include <cstdint>

class PackageLocation
{
public:
    virtual ~PackageLocation();
};

class TESPackageData
{
public:
    virtual ~TESPackageData() {}
};

class Unk4a1000 : public TESPackageData
{
public:
    // The constructor only emits the vftable and with it the deleting destructor.
    Unk4a1000();
    ~Unk4a1000() override
    {
        delete pStartLocation;
    }

    PackageLocation* pStartLocation;
    std::uint64_t unk10;
};
static_assert(sizeof(Unk4a1000) == 0x18, "follow package data layout");
