// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialParallaxOcc, BSLightingShaderMaterialBase, ClearTextures, heightTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSourceTexture, _refCount, DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x15264e0 BSLightingShaderMaterialParallaxOcc::ClearTextures
#include "BSLightingShaderMaterialParallaxOcc_15264e0.h"

void BSLightingShaderMaterialParallaxOcc::ClearTextures()
{
    BSLightingShaderMaterialBase::ClearTextures();
    NiSourceTexture* previous = heightTexture;
    if (previous) {
        heightTexture = nullptr;
        // Intrusive ownership releases must update the count atomically.
        if (_InterlockedExchangeAdd(&previous->_refCount, -1) == 1) {
            previous->DeleteThis();
        }
    }
}
