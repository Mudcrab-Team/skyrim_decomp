// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout for terrain inheritance and height data.
// TESWorldSpace, BGSTerrainManager, terrainManager, parentUseFlags, parentWorld, northRotation, HasMaxHeightData, maxHeightData, kUseLODData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetTerrainManager: GUESS(low)
#pragma once

#include <cstdint>

class BGSTerrainManager;

class TESWorldSpace
{
public:
    BGSTerrainManager* GetTerrainManager() const;
    bool HasMaxHeightData() const;

    std::uint8_t unknown000[0x90];
    BGSTerrainManager* terrainManager;
    std::uint8_t unknown098[0xa];
    std::uint16_t parentUseFlags;
    std::uint8_t unknown0a4[0xb4];
    TESWorldSpace* parentWorld;
    std::uint8_t unknown160[0x1e8];
    float northRotation;
    std::uint32_t unknown34c;
    std::int8_t* maxHeightData;
};
