// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1525270 BSLightingShaderMaterialEye::Create
// 0x15256d0 BSLightingShaderMaterialEye::GetTextures
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1525770 BSLightingShaderMaterialEye::SaveBinary
// 0x15257f0 BSLightingShaderMaterialEye::LoadBinary
// 0x1525640 BSLightingShaderMaterialEye::ReceiveValuesFromRootMaterial
// 0x15250e0 BSLightingShaderMaterialEye::Ctor
#include "BSLightingShaderMaterialEye.h"

// componentSize: GUESS(low)
void BSLightingShaderMaterialEye::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    { std::uint32_t componentSize = 4;
    a_stream.oStr->binary_write(&unkB0, 4, &componentSize); }
    colorB4.SaveBinary2(a_stream);
    return colorC0.SaveBinary2(a_stream);
}
// componentSize: GUESS(low)
void BSLightingShaderMaterialEye::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    { std::uint32_t componentSize = 4;
    a_stream.iStr->binary_read(&unkB0, 4, &componentSize); }
    colorB4.LoadBinary2(a_stream);
    return colorC0.LoadBinary2(a_stream);
}


// Accepted leaf retained from the integrated version.
// GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
BSShaderMaterial::Feature BSLightingShaderMaterialEye::GetFeature() const
{
    return static_cast<Feature>(0x10);
}

// Additional bodies drafted by gpt-6.1-sol from the assigned pack.
// envMask, cubemap: GUESS(low); candidate references to shared default textures.
void BSLightingShaderMaterialEye::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, std::uintptr_t a_extra1, std::uintptr_t a_extra2)
{
    BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial(a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_extra1, a_extra2);
    if (!eyeEnvMask._ptr) {
        NiSourceTexture* envMask = g_defaultEnvMask;
        if (envMask) { envMask->IncRefCount(); eyeEnvMask._ptr = envMask; }
    }
    if (!eyeCubemap._ptr) {
        NiSourceTexture* cubemap = g_defaultCubemap;
        if (cubemap) { cubemap->IncRefCount(); eyeCubemap._ptr = cubemap; }
    }
}

BSLightingShaderMaterialEye::BSLightingShaderMaterialEye() : eyeEnvMask{}, eyeCubemap{}, unkB0(1.0f), colorB4(), colorC0()
{
    colorB4.red = NiPoint3::Zero.x;
    colorB4.green = NiPoint3::Zero.y;
    colorB4.blue = NiPoint3::Zero.z;
    colorC0.red = NiPoint3::Zero.x;
    colorC0.green = NiPoint3::Zero.y;
    colorC0.blue = NiPoint3::Zero.z;
}


void* BSLightingShaderMaterialEye::operator new(std::size_t a_size) throw()
{
    if (g_memoryManagerGuard != 2) {
        InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
    }
    return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
}

BSShaderMaterial* BSLightingShaderMaterialEye::Create()
{
    return new BSLightingShaderMaterialEye;
}

std::uint32_t BSLightingShaderMaterialEye::GetTextures(NiSourceTexture** a_textures)
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
    if (eyeEnvMask) {
        a_textures[count++] = eyeEnvMask._ptr;
    }
    if (eyeCubemap) {
        a_textures[count++] = eyeCubemap._ptr;
    }
    return count;
}
