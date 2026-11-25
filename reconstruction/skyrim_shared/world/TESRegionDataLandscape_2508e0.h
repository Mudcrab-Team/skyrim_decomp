// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataLandscape.cpp:33
// TESRegionDataLandscape, TESRegionDataLandscape::~TESRegionDataLandscape: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionDataLandscape::icon, TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRegionData, TESRegionData::~TESRegionData: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// unk08: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

// Reduced to the virtual destructor the owner calls through.
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

    TESTexture* icon;  // 10
};
static_assert(sizeof(TESRegionDataLandscape) == 0x18, "TESRegionDataLandscape size");
