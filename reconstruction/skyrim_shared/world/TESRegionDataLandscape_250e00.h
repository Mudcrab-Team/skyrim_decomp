// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESRegionDataLandscape::~TESRegionDataLandscape follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp:213
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp:75
// TESRegionDataLandscape, TESRegionDataLandscape::~TESRegionDataLandscape, icon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRegionData, TESRegionData::~TESRegionData, TESTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08: GUESS(low)
// TESRegionDataLandscape::TESRegionDataLandscape: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); emits the vftable.
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class TESTexture
{
public:
    virtual ~TESTexture();
};

class TESRegionDataLandscape : public TESRegionData
{
public:
    TESRegionDataLandscape();
    ~TESRegionDataLandscape() override;

    TESTexture* icon;
};
static_assert(sizeof(TESRegionDataLandscape) == 0x18, "landscape region data layout");
