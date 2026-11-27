// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky, Sky::sub_1403B6250, Sky::extLightingOverride, Sky::skyColorUnknown, Sky::skyColorSunlight, Sky::skyColorSun, Sky::skyColorSkyStatics, BGSLightingTemplate, TESObjectCELL, TES, NiColor, GetSky: CRASHLOGGER_PDB(59818@2026.10.24)
// TES::interiorCell, NiColor::red, NiColor::green, NiColor::blue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_tes, Function295690, Function295610, Function2957a0, Function295800, Function2bbf30, Function2bbe40, Function2bc1b0, Function2bc240, unk00, unk30, unkC0, unkE4: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiColor
{
    float red;
    float green;
    float blue;
};

class BGSLightingTemplate
{
public:
    void Function295690(NiColor& a_out);
    void Function295610(NiColor& a_out);
    void Function2957a0(NiColor& a_out);
    void Function295800(NiColor& a_out);
};

class TESObjectCELL
{
public:
    void Function2bbf30(NiColor& a_out);
    void Function2bbe40(NiColor& a_out);
    void Function2bc1b0(NiColor& a_out);
    void Function2bc240(NiColor& a_out);
};

class TES
{
public:
    std::uint8_t unk00[0xc0];
    TESObjectCELL* interiorCell;  // C0
};
static_assert(offsetof(TES, interiorCell) == 0xc0, "TES interiorCell offset");

extern TES* g_tes;

class Sky
{
public:
    static Sky* GetSky();

    void sub_1403B6250(BGSLightingTemplate* a_template, NiColor& a_c1, NiColor& a_c2, NiColor& a_c3, NiColor& a_c4);  // compared: 0x416ca0

    std::uint8_t unk00[0x28];
    BGSLightingTemplate* extLightingOverride;  // 28
    std::uint8_t unk30[0xb4 - 0x30];
    NiColor skyColorUnknown;                   // B4
    std::uint8_t unkC0[0xcc - 0xc0];
    NiColor skyColorSunlight;                  // CC
    NiColor skyColorSun;                       // D8
    std::uint8_t unkE4[0x138 - 0xe4];
    NiColor skyColorSkyStatics;                // 138
};
static_assert(offsetof(Sky, extLightingOverride) == 0x28, "Sky extLightingOverride offset");
static_assert(offsetof(Sky, skyColorUnknown) == 0xb4, "Sky skyColorUnknown offset");
static_assert(offsetof(Sky, skyColorSunlight) == 0xcc, "Sky skyColorSunlight offset");
static_assert(offsetof(Sky, skyColorSun) == 0xd8, "Sky skyColorSun offset");
static_assert(offsetof(Sky, skyColorSkyStatics) == 0x138, "Sky skyColorSkyStatics offset");
