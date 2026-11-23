// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1527e60 BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial
// Adapted bodies: none
#include "BSLightingShaderMaterialLODLandscape_1527e60.h"

void BSLightingShaderMaterialLODLandscape::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting,
    bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unk6, void* a_unk7)
{
    BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial(a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_unk6, a_unk7);
    if (!landscapeNoiseTexture) {
        NiTextureStandIn* tex = g_defaultTexture;
        if (tex) {
            // smart pointer refcounts are shared across threads, so atomic
            _InterlockedIncrement(&tex->m_uiRefCount);
            landscapeNoiseTexture = tex;
        }
    }
    if (!parentNormalTexture) {
        NiTextureStandIn* tex = g_defaultTexture;
        if (tex) {
            // smart pointer refcounts are shared across threads, so atomic
            _InterlockedIncrement(&tex->m_uiRefCount);
            parentNormalTexture = tex;
        }
    }
    if (!parentDiffuseTexture) {
        NiTextureStandIn* tex = g_defaultTexture;
        if (tex) {
            // smart pointer refcounts are shared across threads, so atomic
            _InterlockedIncrement(&tex->m_uiRefCount);
            parentDiffuseTexture = tex;
        }
    }
}
