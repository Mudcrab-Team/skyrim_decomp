// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterNormals, TESWaterNormals::flags, TESWaterNormals::waterType, TESWaterNormals::unk20, TESWaterNormals::waterMaterial, TESWaterNormals::noiseLayer0, TESWaterNormals::noiseLayer1, TESWaterNormals::noiseLayer2, TESWaterNormals::noiseLayer3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets
// TESWaterForm, BSWaterShaderMaterial, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared only
// TexturePointer, ReleaseTexture: GUESS(low); the texture holder releases through the callee at 0x24dc20, which accepts a null pointer
// NiRefObject, NiRefObject::DeleteThis: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// g_niObjectCount: GUESS(low); the global object counter
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

// volatile: the counter is changed atomically with interlocked operations
extern volatile long g_niObjectCount;

class NiRefObject
{
public:
    // hot path: the engine counts live objects atomically
    virtual ~NiRefObject() { _InterlockedDecrement(&g_niObjectCount); }
    virtual void DeleteThis();  // 01

    std::uint32_t m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

class TESWaterForm;
class BSWaterShaderMaterial;
class NiSourceTexture;

void ReleaseTexture(NiSourceTexture* a_texture) noexcept;  // callee at 0x24dc20, not compared here

class TexturePointer
{
public:
    ~TexturePointer() { ReleaseTexture(_ptr); }
    TexturePointer& operator=(decltype(nullptr))
    {
        if (_ptr) {
            NiSourceTexture* old = _ptr;
            _ptr = nullptr;
            ReleaseTexture(old);
        }
        return *this;
    }

    NiSourceTexture* _ptr;
};

class TESWaterNormals : public NiRefObject
{
public:
    TESWaterNormals();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x52eff0
    ~TESWaterNormals() override;

    std::uint8_t flags;                    // 10
    TESWaterForm* waterType;               // 18
    std::uint32_t unk20;                   // 20
    BSWaterShaderMaterial* waterMaterial;  // 28
    TexturePointer noiseLayer0;            // 30
    TexturePointer noiseLayer1;            // 38
    TexturePointer noiseLayer2;            // 40
    TexturePointer noiseLayer3;            // 48
};
static_assert(sizeof(TESWaterNormals) == 0x50, "TESWaterNormals size");
