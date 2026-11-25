// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialGlowmap, CopyMembers, glowTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Cookbook: 29
// 0x15259d0 BSLightingShaderMaterialGlowmap::CopyMembers
#include "BSLightingShaderMaterialGlowmap_15259d0.h"

void BSLightingShaderMaterialGlowmap::CopyMembers(BSShaderMaterial* other)
{
    BSLightingShaderMaterialBase::CopyMembers(other);
    NiSourceTexture* previous = glowTexture;
    NiSourceTexture* incoming = static_cast<BSLightingShaderMaterialGlowmap*>(other)->glowTexture;
    if (previous != incoming) {
        if (incoming) {
            incoming->IncRefCount();
        }
        glowTexture = incoming;
        if (previous) {
            previous->DecRefCount();
        }
    }
}
