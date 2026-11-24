// Source exposure: mixed (community and sibling declarations, pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTexture, NiPointer, NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DeleteThis, IncRefCount, DecRefCount, _refCount, _pad0C, get, _ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderManager, GetTexture: CRASHLOGGER_PDB(59818@2026.10.24) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LookupTexture, LoadTexture, textureLoadMode, g_defaultTexture, g_defaultHeightTexture: GUESS(low)
// kSpecialDefault, kSpecialFallback, kMissingTextureFormat, kSpecialPathMarker, kPathCapacity: GUESS(low)
// sprintf_s: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: BSShaderManager::GetTexture follows momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshadermanager.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshadermanager.cpp:270
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
        if (_ptr != other._ptr) {
            T* previous = _ptr;
            T* incoming = other._ptr;
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
    static void GetTexture(const char* path, bool demand, NiPointer<NiTexture>& out, bool isHeightMap);
};

void LoadTexture(const char* path, NiPointer<NiTexture>& out, bool demand, bool isHeightMap,
    std::uint32_t mode, bool keepSource, bool cube);
void LookupTexture(const char* path, NiPointer<NiTexture>& out);

extern __declspec(thread) std::uint32_t textureLoadMode;
extern NiTexture* g_defaultTexture;
extern NiTexture* g_defaultHeightTexture;
extern const char kSpecialDefault[];
extern const char kSpecialFallback[];
extern const char kMissingTextureFormat[];
