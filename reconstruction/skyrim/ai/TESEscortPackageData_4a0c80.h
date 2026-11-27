// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESEscortPackageData::~TESEscortPackageData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/packagedataescort.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/packagedataescort.cpp:93
// TESEscortPackageData, TESEscortPackageData::~TESEscortPackageData: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// PackageLocation, PackageLocation::~PackageLocation, TESPackageData, TESPackageData::~TESPackageData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pSearchLocation, iFollowPackRadius: SYMBOLS(fo4-pdb)
// unk14: GUESS(low)
// TESEscortPackageData::TESEscortPackageData: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); emits the vftable.
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

class TESEscortPackageData : public TESPackageData
{
public:
    TESEscortPackageData();
    ~TESEscortPackageData() override;

    PackageLocation* pSearchLocation;
    std::int32_t iFollowPackRadius;
    std::uint32_t unk14;
};
static_assert(sizeof(TESEscortPackageData) == 0x18, "escort package data layout");
