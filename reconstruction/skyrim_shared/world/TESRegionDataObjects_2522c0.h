// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataObjects.cpp:112
// TESRegionDataObjects, TESRegionDataObjects::~TESRegionDataObjects: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionData, TESRegionData::~TESRegionData, TESRegionObjectList: STANDIN SIBLING(fo4-private@1b765c70, author-permission); reduced to the virtual destructor
// unk08, pObjects, unk18: GUESS(low); pObjects is the member name the sibling body uses
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class TESRegionObjectList
{
public:
    virtual ~TESRegionObjectList();
};

class TESRegionDataObjects : public TESRegionData
{
public:
    TESRegionDataObjects();
    ~TESRegionDataObjects() override;

    TESRegionObjectList* pObjects;  // 10
    std::uint8_t unk18;             // 18
};
