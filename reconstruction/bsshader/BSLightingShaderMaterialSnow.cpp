// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1529210 BSLightingShaderMaterialSnow::~BSLightingShaderMaterialSnow
// Code origin: SaveBinary and LoadBinary bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1528120 BSLightingShaderMaterialSnow::SaveBinary
// 0x1528160 BSLightingShaderMaterialSnow::LoadBinary
// 0x1528110 BSLightingShaderMaterialSnow::GetFeature
// 0x1528090 BSLightingShaderMaterialSnow::CopyMembers
// 0x1527fc0 BSLightingShaderMaterialSnow::Ctor
// 0x15280d0 BSLightingShaderMaterialSnow::ComputeCRC32
#include "BSLightingShaderMaterialSnow.h"
void BSLightingShaderMaterialSnow::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    unknownA0.SaveStream(a_stream);
}
void BSLightingShaderMaterialSnow::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    unknownA0.LoadStream(a_stream);
}
#include <new>

// SnowDefaults: STANDIN GUESS(low)
using SnowDefaults = BSLightingShaderMaterialSnow::SnowData;
// g_snowDefaults: GUESS(low)
extern SnowDefaults g_snowDefaults;
// BaseCopyHelper: GUESS(low)
void BaseCopyHelper(BSLightingShaderMaterialBase* a_this, BSShaderMaterial* a_src);
// SnowCRCSeed: GUESS(low)
std::uint32_t SnowCRCSeed();
// CRC32Size: GUESS(low)
void CRC32Size(std::uint32_t* a_out, const void* a_data, std::uint32_t a_size);

BSShaderMaterial::Feature BSLightingShaderMaterialSnow::GetFeature() const
{
    return static_cast<Feature>(0xE);
}

void BSLightingShaderMaterialSnow::CopyMembers(BSShaderMaterial* a_src)
{
    BaseCopyHelper(this, a_src);
    unknownA0 = static_cast<BSLightingShaderMaterialSnow*>(a_src)->unknownA0;
}

BSLightingShaderMaterialSnow::BSLightingShaderMaterialSnow() :
    unknownA0(g_snowDefaults)
{}

BSLightingShaderMaterialSnow* BSLightingShaderMaterialSnow::Ctor()
{
    return new (this) BSLightingShaderMaterialSnow;
}

std::uint32_t BSLightingShaderMaterialSnow::ComputeCRC32()
{
    struct SnowBlock {
        SnowData data;
        std::uint32_t seed;
    } block{unknownA0, SnowCRCSeed()};
    std::uint32_t result;
    CRC32Size(&result, &block, 0x14);
    return result;
}
