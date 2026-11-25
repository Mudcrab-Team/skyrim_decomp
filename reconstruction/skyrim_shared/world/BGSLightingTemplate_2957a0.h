// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/BGSLightingTemplate.cpp:129
// BGSLightingTemplate, BGSLightingTemplate::GetDataAmbientColor, BGSLightingTemplate::Data, NiColor, NiColor::r, NiColor::g, NiColor::b: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
// LightingData, iAmbient, unk20_, unk00: GUESS(low); the ambient colour word sits at 0x28 in the listing, the first 8 bytes of the data block are unknown
#pragma once

#include <cstdint>

struct NiColor
{
    float r;
    float g;
    float b;
};

struct LightingData
{
    std::uint8_t  unk00[8];
    std::uint32_t iAmbient;  // 08
};

class BGSLightingTemplate
{
public:
    void GetDataAmbientColor(NiColor& acolColor);

    std::uint8_t unk20_[0x20];  // 00
    LightingData Data;          // 20
};
static_assert(sizeof(BGSLightingTemplate) == 0x2C, "BGSLightingTemplate stand-in size");
