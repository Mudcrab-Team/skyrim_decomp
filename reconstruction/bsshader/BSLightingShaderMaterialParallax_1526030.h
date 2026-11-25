// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialParallax, BSLightingShaderMaterialBase, ClearTextures, heightTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSourceTexture, NiRefObject, DeleteThis, _refCount: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// vptr: OBSERVED
// unknown08: GUESS(low); unaccessed base storage.
#pragma once
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    // volatile: intrusive reference count is shared across threads.
    volatile long _refCount;
};
static_assert(offsetof(NiRefObject, _refCount) == 0x08, "reference count offset");
class NiSourceTexture : public NiRefObject {};

// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Partial base declaration preserves the observed height-texture offset.
class BSLightingShaderMaterialBase
{
public:
    void ClearTextures();
    void* vptr;
    unsigned char unknown08[0x98];
};
class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
{
public:
    void ClearTextures();
    NiSourceTexture* heightTexture;
};
static_assert(offsetof(BSLightingShaderMaterialParallax, heightTexture) == 0xA0, "heightTexture offset");
