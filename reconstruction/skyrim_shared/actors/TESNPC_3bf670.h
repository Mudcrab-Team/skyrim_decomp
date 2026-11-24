// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESNPC::GetHairColor, FaceData, ColorForm: GUESS(low) STANDIN
// TESNPC::IsFemale: CRASHLOGGER_PDB(59818@2026.10.24)
// IsFemale return type: OBSERVED; the caller sign-extends an int result
// color: GUESS(low); BGSColorForm::color is the community name at this offset
// headRelatedData, race, faceRelatedData, defaultHairColor, hairColor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; offsets and names only
#pragma once

#include <cstdint>
#include <cstddef>

struct ColorForm
{
    std::uint8_t pad00[0x30];
    std::uint32_t color;  // 30
};

struct FaceRelatedData
{
    std::uint8_t pad00[0xB8];
    ColorForm* defaultHairColor;  // B8
};

struct TESRace
{
    std::uint8_t pad00[0x4A8];
    FaceRelatedData* faceRelatedData[2];  // 4A8
};

struct HeadRelatedData
{
    ColorForm* hairColor;  // 00
};

class TESNPC
{
public:
    std::int32_t IsFemale() const;
    std::uint32_t GetHairColor() const;  // compared: 0x3bf670

    std::uint8_t pad00[0x158];
    TESRace* race;                       // 158
    std::uint8_t pad160[0x1C8 - 0x160];
    HeadRelatedData* headRelatedData;    // 1C8
};
