// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterForm::InitializeData: CRASHLOGGER_PDB(59818@2026.10.24); name only
// TESWaterForm, TESWaterForm::alpha, TESWaterForm::flags, TESWaterForm::materialType, TESWaterForm::waterSound, TESWaterForm::data, TESWaterForm::waterWeatherControl, TESWaterForm::imageSpace, TESWaterForm::linearVelocity, TESWaterForm::angularVelocity: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets
// WaterShaderData, NiPoint3, NiPoint3::operator[], BGSMaterialType, BGSSoundDescriptorForm, TESImageSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// WaterShaderData::Function305f40, g_defaultAngularVelocity: GUESS(low); the callee at 0x305f40 and the default vector it starts from
// Adapted bodies: none. The origin check reports NiPoint3::operator[] as similar to bodies cited below (sibling files, CC0-1.0) and to CommonLibSSE-NG@b93280e src/RE/N/NiPoint3.cpp (MIT, NiPoint3::operator[]); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a80000_o2.cpp:3643
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3614
#pragma once

#include <cstdint>
#include <cstddef>

class BGSMaterialType;
class BGSSoundDescriptorForm;
class TESImageSpace;

struct NiPoint3
{
    float& operator[](std::size_t a_index) { return (&x)[a_index]; }
    const float& operator[](std::size_t a_index) const { return (&x)[a_index]; }

    float x;
    float y;
    float z;
};

extern float g_defaultAngularVelocityX;
extern float g_defaultAngularVelocityY;
extern float g_defaultAngularVelocityZ;

class WaterShaderData
{
public:
    void Function305f40();  // callee at 0x305f40, not compared here
    std::uint8_t unk00[0xe8];
};
static_assert(sizeof(WaterShaderData) == 0xe8, "WaterShaderData size");

class TESWaterForm
{
public:
    void InitializeData();  // compared: 0x306520

    std::uint8_t unk00[0xb8];
    std::int8_t alpha;                          // B8
    std::uint8_t flags;                         // B9
    BGSMaterialType* materialType;              // C0
    BGSSoundDescriptorForm* waterSound;         // C8
    WaterShaderData data;                       // D0
    TESWaterForm* waterWeatherControl[3];       // 1B8
    std::uint8_t unk1D0[0x240 - 0x1d0];         // 1D0
    TESImageSpace* imageSpace;                  // 240
    NiPoint3 linearVelocity;                    // 248
    NiPoint3 angularVelocity;                   // 254
};
static_assert(offsetof(TESWaterForm, angularVelocity) == 0x254, "layout");
