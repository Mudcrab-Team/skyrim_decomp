// Source exposure: mixed (community and sibling declarations, pinned image listing).
// Code origin: Stand-in declarations from the pinned image and labelled sources. The pointer handling follows the cited sibling routines.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTexture, NiSourceTexture, NiPointer, NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DeleteThis, IncRefCount, DecRefCount, _refCount, _pad0C, get, _ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderTextureSet, SetTexture: CRASHLOGGER_PDB(59818@2026.10.24) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderManager, GetTexture, GetTexturePath, Texture, kHeight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetTexture: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); lookup with an output reference
// vslot00, vslot01, vslot02, vslot03, vslot04, vslot05, vslot06, vslot07, vslot08, vslot09, vslot0A, vslot0B, vslot0C, vslot0D, vslot0E, vslot0F, vslot10, vslot11, vslot12, vslot13, vslot14, vslot15, vslot16, vslot17, vslot18, vslot19, vslot1A, vslot1B, vslot1C, vslot1D, vslot1E, vslot1F, vslot20, vslot21, vslot22, vslot23, vslot24: GUESS(low); unused virtual slots before GetTexturePath
// Adapted bodies: BSShaderTextureSet::SetTexture follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:68
// Adapted bodies: BSShaderTextureSet::GetTexture follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:27
// Adapted bodies: NiRefObject::IncRefCount, NiPointer::~NiPointer and NiPointer::operator= follow the cited intrusive pointer routines.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/boltshader.cpp:27
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/distantlodshader_decls.h:21
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsmenu/debugtext_ob1_variant.cpp:1509
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/shadowscenenode.cpp:72
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2_2.cpp:1754
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // The texture cache shares reference counts across threads.
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_refCount));
    }

    void DecRefCount()
    {
        // Release atomically so only the last owner deletes the object.
        std::uint32_t count = static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&_refCount)));
        if (count == 0) {
            DeleteThis();
        }
    }

private:
    volatile std::uint32_t _refCount;
    std::uint32_t _pad0C;
};

class NiTexture : public NiRefObject
{
};

class NiSourceTexture : public NiTexture
{
};

template <class T>
class NiPointer
{
public:
    NiPointer() = default;

    NiPointer(const NiPointer& other) : _ptr(other._ptr)
    {
        if (_ptr) {
            _ptr->IncRefCount();
        }
    }

    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

    NiPointer& operator=(const NiPointer& other)
    {
        T* previous = _ptr;
        T* incoming = other._ptr;
        if (previous != incoming) {
            if (incoming) {
                incoming->IncRefCount();
            }
            _ptr = incoming;
            if (previous) {
                previous->DecRefCount();
            }
        }
        return *this;
    }

    NiPointer& operator=(T* incoming)
    {
        T* previous = _ptr;
        if (previous != incoming) {
            if (incoming) {
                incoming->IncRefCount();
            }
            _ptr = incoming;
            if (previous) {
                previous->DecRefCount();
            }
        }
        return *this;
    }

    T* get() const { return _ptr; }

private:
    T* _ptr{ nullptr };
};

class BSShaderManager
{
public:
    static void GetTexture(const char* path, bool demand, NiPointer<NiSourceTexture>& out, bool isHeightMap);
};

enum Texture : std::uint32_t
{
    kHeight = 4
};

class BSShaderTextureSet
{
public:
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0A();
    virtual void vslot0B();
    virtual void vslot0C();
    virtual void vslot0D();
    virtual void vslot0E();
    virtual void vslot0F();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1A();
    virtual void vslot1B();
    virtual void vslot1C();
    virtual void vslot1D();
    virtual void vslot1E();
    virtual void vslot1F();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual const char* GetTexturePath(Texture texture);
    virtual void SetTexture(Texture texture, NiPointer<NiTexture>& out);
};
