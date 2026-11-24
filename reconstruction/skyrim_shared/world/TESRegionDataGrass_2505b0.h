// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataGrass.cpp:28
// TESRegionDataGrass, TESRegionDataGrass::~TESRegionDataGrass: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionData, TESRegionData::~TESRegionData: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionGrassObjectList: STANDIN SIBLING(fo4-private@1b765c70, author-permission); only its virtual destructor is needed
// unk08, pObjects: GUESS(low); pObjects is the member name the sibling body uses
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class TESRegionGrassObjectList
{
public:
    virtual ~TESRegionGrassObjectList();
};

class TESRegionDataGrass : public TESRegionData
{
public:
    TESRegionDataGrass();
    ~TESRegionDataGrass() override;

    TESRegionGrassObjectList* pObjects;  // 10
};
static_assert(sizeof(TESRegionDataGrass) == 0x18, "TESRegionDataGrass size");
