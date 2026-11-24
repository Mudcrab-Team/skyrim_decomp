// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSBodyPartData, BGSBodyPartData::ClearData, BGSBodyPartData::parts, BGSBodyPart: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unknown80, unknown00: GUESS(low)
// Adapted bodies: BGSBodyPartData::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:50
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:58
#pragma once

#include <cstddef>
#include <cstdint>
#include "declarations/TESForm.h"

class BGSBodyPart
{
public:
    ~BGSBodyPart();
    std::uint8_t unknown00[0xF0];
};

class BGSBodyPartData : public TESForm
{
public:
    void ClearData() override;

    std::uint8_t unknown20[0x30];
    BGSBodyPart* parts[6];
    std::uint8_t unknown80[8];
};
static_assert(sizeof(BGSBodyPart) == 0xF0, "BGSBodyPart size");
static_assert(sizeof(BGSBodyPartData) == 0x88, "BGSBodyPartData size");
