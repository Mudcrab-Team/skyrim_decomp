// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1524a60 BSLightingShaderMaterialEnvmap::Ctor
// 0x1524f10 BSLightingShaderMaterialEnvmap::ReceiveValuesFromRootMaterial
// 0x1524f80 BSLightingShaderMaterialEnvmap::GetTextures
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1525020 BSLightingShaderMaterialEnvmap::SaveBinary
// 0x1525080 BSLightingShaderMaterialEnvmap::LoadBinary
// 0x1524ce0 BSLightingShaderMaterialEnvmap::ComputeCRC32
#include "BSLightingShaderMaterialEnvmap.h"

// RVA 0x1525020, 82 bytes: the base writes its own fields, then this writes the float.
void BSLightingShaderMaterialEnvmap::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    std::uint32_t componentSize = 4;
    a_stream.oStr->binary_write(&unkB0, 4, &componentSize);
}

// RVA 0x1525080, 82 bytes: the mirror of SaveBinary on the input stream.
void BSLightingShaderMaterialEnvmap::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    std::uint32_t componentSize = 4;
    a_stream.iStr->binary_read(&unkB0, 4, &componentSize);
}
// EnvmapCrcRecord: GUESS(low); the 0x10-byte record hashed by ComputeCRC32, laid out as the image writes it
struct EnvmapCrcRecord
{
    std::uint32_t ids[2];    // 00
    float         unkB0;     // 08
    std::uint32_t flagHash;  // 0C
};
static_assert(sizeof(EnvmapCrcRecord) == 0x10, "EnvmapCrcRecord size");

// RVA 0x1524ce0, 161 bytes: hashes the two texture ids, the float and a flag hash as one record.
std::uint32_t BSLightingShaderMaterialEnvmap::ComputeCRC32(std::uint32_t a_flags)
{
    EnvmapCrcRecord record;
    if (textureSet._ptr) {
        CRC32Calculator::SizeOf32(&record.ids[0], textureSet._ptr->Unk_25(4), 0);
        CRC32Calculator::SizeOf32(&record.ids[1], textureSet._ptr->Unk_25(5), 0);
    }
    else {
        record.ids[0] = 0;
        record.ids[1] = 0;
    }
    record.unkB0 = unkB0;
    record.flagHash = ComputeFlagHash(a_flags);
    std::uint32_t out[2];
    CRC32Calculator::SizeOfSize(out, &record, 0x10);
    return out[0];
}

// Retained generated leaf; its byte-match evidence is renewed with this unit.
// GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
BSShaderMaterial::Feature BSLightingShaderMaterialEnvmap::GetFeature() const
{
    return static_cast<Feature>(0x1);
}

#include <new>

// BaseReceiveValues: GUESS(low); the base function as the image calls it, with the two extra pointer arguments
void BaseReceiveValues(BSLightingShaderMaterialBase* a_this, bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unk6, void* a_unk7);  // 0x1523f00

BSLightingShaderMaterialEnvmap::BSLightingShaderMaterialEnvmap() :
    unkA0Texture{},
    unkA8Texture{},
    unkB0(1.0f)
{}

BSLightingShaderMaterialEnvmap* BSLightingShaderMaterialEnvmap::Ctor()
{
    return ::new (this) BSLightingShaderMaterialEnvmap;
}

void BSLightingShaderMaterialEnvmap::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unk6, void* a_unk7)
{
    BaseReceiveValues(this, a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_unk6, a_unk7);
    if (!unkA0Texture) {
        unkA0Texture = g_defaultEnvmapTexture;
    }
}

std::uint32_t BSLightingShaderMaterialEnvmap::GetTextures(NiSourceTexture** a_textures)
{
    std::uint32_t count = 0;
    if (diffuseTexture) {
        a_textures[count++] = diffuseTexture._ptr;
    }
    if (normalTexture) {
        a_textures[count++] = normalTexture._ptr;
    }
    if (rimSoftLightingTexture) {
        a_textures[count++] = rimSoftLightingTexture._ptr;
    }
    if (specularBackLightingTexture) {
        a_textures[count++] = specularBackLightingTexture._ptr;
    }
    if (unkA0Texture) {
        a_textures[count++] = unkA0Texture._ptr;
    }
    if (unkA8Texture) {
        a_textures[count++] = unkA8Texture._ptr;
    }
    return count;
}
