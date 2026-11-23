// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSLightingShaderMaterialLODLandscape, BSLightingShaderMaterialBase, NiTextureStandIn: GUESS(low); class views are stand-ins
// ReceiveValuesFromRootMaterial: CRASHLOGGER_PDB(59818@2026.10.24)
// parentDiffuseTexture, parentNormalTexture, landscapeNoiseTexture: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

// Minimal stand-in: a reference counted texture.
class NiTextureStandIn
{
public:
    virtual ~NiTextureStandIn();
    volatile long m_uiRefCount;
};

extern NiTextureStandIn* g_defaultTexture;

class BSLightingShaderMaterialBase
{
public:
    void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting,
        bool a_MSN, void* a_unk6, void* a_unk7);

    virtual ~BSLightingShaderMaterialBase();
    std::uint8_t unk08[0x98];
};

class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
{
public:
    void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting,
        bool a_MSN, void* a_unk6, void* a_unk7);  // compared: 0x1527e60

    NiTextureStandIn* parentDiffuseTexture;
    NiTextureStandIn* parentNormalTexture;
    NiTextureStandIn* landscapeNoiseTexture;
};
