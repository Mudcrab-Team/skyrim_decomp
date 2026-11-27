// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialGlowmap, BSLightingShaderMaterialBase, BSShaderMaterial, ReceiveValuesFromRootMaterial, glowTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, NiSourceTexture, DeleteThis, _refCount, IncRefCount, DecRefCount: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk38Arg, unk40Arg: GUESS(low); additional observed forwarded pointer arguments.
// unk08, unk38: GUESS(low); unmodelled material storage.
// The target forwards two pointer arguments beyond the community five-bool declaration.
// gDefaultGlowTexture: GUESS(low); fallback texture reference.
#pragma once
#include <intrin.h>
#include <cstddef>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        // Intrusive references are shared between render workers.
        _InterlockedIncrement(&_refCount);
    }
    void DecRefCount()
    {
        // Release must atomically detect the last owner.
        long count = _InterlockedDecrement(&_refCount);
        if (count == 0) {
            DeleteThis();
        }
    }
    // volatile: intrusive reference count is accessed with interlocked operations.
    volatile long _refCount;
};
class NiSourceTexture : public NiRefObject {};
class BSShaderMaterial
{
public:
    virtual ~BSShaderMaterial();
    unsigned char unk08[0x30];
};
class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
    void ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool MSN, void* unk38Arg, void* unk40Arg);
    unsigned char unk38[0x68];
};
class BSLightingShaderMaterialGlowmap : public BSLightingShaderMaterialBase
{
public:
    void ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool MSN, void* unk38Arg, void* unk40Arg);
    NiSourceTexture* glowTexture;
};
static_assert(offsetof(BSLightingShaderMaterialGlowmap, glowTexture) == 0xA0, "glow texture offset");

extern NiSourceTexture* gDefaultGlowTexture;
