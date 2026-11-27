// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectLAND: EXE_RTTI
// TESObjectLAND::sub_14025B9B0: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectLAND::loadedData, LoadedLandData, NiColorA, NiColorA::red, NiColorA::green, NiColorA::blue, NiColorA::alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::unk00, LoadedLandData::unk0000, LoadedLandData::colors, VertexColorRGB, VertexColorRGB::r, VertexColorRGB::g, VertexColorRGB::b, g_defaultLandColor: GUESS(low); offsets and global observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

struct NiColorA
{
    float red;    // 00
    float green;  // 04
    float blue;   // 08
    float alpha;  // 0C
};

extern NiColorA g_defaultLandColor;

struct VertexColorRGB
{
    std::uint8_t r;  // 00
    std::uint8_t g;  // 01
    std::uint8_t b;  // 02
};
static_assert(sizeof(VertexColorRGB) == 3, "VertexColorRGB size");

struct LoadedLandData
{
    std::uint8_t   unk0000[0x2D48];  // 0000
    VertexColorRGB colors[4][289];   // 2D48
};
static_assert(offsetof(LoadedLandData, colors) == 0x2D48, "LoadedLandData::colors offset");

class TESObjectLAND
{
public:
    void sub_14025B9B0(std::int32_t a_quad, std::int32_t a_vertex, NiColorA& a_out) const;

    std::uint8_t    unk00[0x40];  // 00
    LoadedLandData* loadedData;   // 40
};
static_assert(offsetof(TESObjectLAND, loadedData) == 0x40, "TESObjectLAND::loadedData offset");
