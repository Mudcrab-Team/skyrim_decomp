// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESRegionDataMap::~TESRegionDataMap follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatamap.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatamap.cpp:95
// TESRegionDataMap, TESRegionDataMap::~TESRegionDataMap, mapName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRegionData, TESRegionData::~TESRegionData, BSFixedString, BSFixedString::~BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk00: GUESS(low)
// TESRegionDataMap::TESRegionDataMap: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); emits the vftable.
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class BSFixedString
{
public:
    ~BSFixedString();

    const char* unk00;
};

class TESRegionDataMap : public TESRegionData
{
public:
    TESRegionDataMap();
    ~TESRegionDataMap() override;

    BSFixedString mapName;
};
static_assert(sizeof(TESRegionDataMap) == 0x18, "map region data layout");
