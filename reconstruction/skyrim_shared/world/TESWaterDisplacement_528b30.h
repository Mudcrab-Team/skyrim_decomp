// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterDisplacement, TESWaterDisplacement::unk1C, TESWaterDisplacement::displacementGeometry, NiAVObject, BSGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches; unk1C holds the stencil index here
// NiAVObject::AsGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; virtual slot 07
// TESWaterDisplacement::Function528b30, g_displacementCount, BSShaderProperty, BSShaderProperty::unk8C, BSGeometry::effectShaderProperty: GUESS(low); the method, the counter and the property member the function writes
#pragma once

#include <cstdint>
#include <cstddef>

struct BSShaderProperty
{
    std::uint8_t unk00[0x8C];
    std::uint32_t unk8C;  // 8C
};

class BSGeometry;

class NiAVObject
{
public:
    virtual ~NiAVObject();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual BSGeometry* AsGeometry();  // 07
};

class BSGeometry : public NiAVObject
{
public:
    std::uint8_t unk08[0x120];
    BSShaderProperty* effectShaderProperty;  // 128
};
static_assert(offsetof(BSGeometry, effectShaderProperty) == 0x128, "layout");

extern std::uint32_t g_displacementCount;

class TESWaterDisplacement
{
public:
    std::uint32_t Function528b30();  // compared: 0x528b30

    std::uint8_t unk00[0x1C];
    std::uint32_t unk1C;                   // 1C
    std::uint8_t unk20[8];
    NiAVObject* displacementGeometry;      // 28
};
static_assert(offsetof(TESWaterDisplacement, displacementGeometry) == 0x28, "layout");
