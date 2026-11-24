// Source exposure: mixed
// Code origin: declarations and inline helpers reconstructed from the pinned image and sources cited in the companion source file.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESEffectShader, TESEffectShader::~TESEffectShader, TESEffectShader::fillTexture, TESEffectShader::particleShaderTexture, TESEffectShader::holesTexture, TESEffectShader::membranePaletteTexture, TESEffectShader::particlePaletteTexture, TESEffectShader::unk210, TESEffectShader::unk218: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture, NiRefObject, NiPointer, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture::~TESTexture, TESTexture::textureName, NiRefObject::~NiRefObject, NiRefObject::DeleteThis, NiRefObject::DecRefCount, NiRefObject::_refCount, NiPointer::_ptr, NiPointer::~NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unkFixedString, unkShaderData: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>
#include "declarations/TESForm.h"

class BSFixedString
{
    const char* unkFixedString;
};

class TESTexture
{
public:
    virtual ~TESTexture();
    BSFixedString textureName;
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void DecRefCount()
    {
        // Intrusive scene objects can release references across threads.
        const long count = _InterlockedDecrement(reinterpret_cast<volatile long*>(&_refCount));
        if (count == 0) {
            DeleteThis();
        }
    }

    volatile std::uint32_t _refCount;
};

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

    T* _ptr;
};

class TESEffectShader : public TESForm
{
public:
    TESEffectShader();
    ~TESEffectShader() override;

    unsigned char unkShaderData[0x1A0];
    TESTexture fillTexture;
    TESTexture particleShaderTexture;
    TESTexture holesTexture;
    TESTexture membranePaletteTexture;
    TESTexture particlePaletteTexture;
    NiPointer<NiRefObject> unk210;
    NiPointer<NiRefObject> unk218;
};

static_assert(offsetof(TESEffectShader, fillTexture) == 0x1C0, "Texture member offset");
static_assert(offsetof(TESEffectShader, unk218) == 0x218, "Last smart pointer offset");
static_assert(sizeof(TESEffectShader) == 0x220, "Size for sized deallocation");
