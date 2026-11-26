// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterReflections, TESWaterReflections::flags, TESWaterReflections::reflectPlane, TESWaterReflections::unk24, TESWaterReflections::cubeMapCamera, TESWaterReflections::unk30, TESWaterReflections::unk38, TESWaterReflections::waterMaterial, TESWaterReflections::unk48, TESWaterReflections::cubeMapSides, CubeMapSide: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets; 30 is released as a counted pointer and 38 is an owned object
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer, BSCubeMapCamera, BSWaterShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// ReflectionTarget, ReflectionTarget::Destroy, SharedReflectionObject: GUESS(low); the object released through virtual slot 15 hex and the type of the pointer at 30
// TESWaterReflections::~TESWaterReflections: GUESS(low); the CrashLogger map calls 0x5281e0 a constructor, but the body releases the members as a destructor does
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// g_niObjectCount: GUESS(low); the global object counter
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
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
    NiRefObject() : m_uiRefCount(0) { _InterlockedIncrement(&g_niObjectCount); }
    // hot path: the engine counts live objects atomically
    virtual ~NiRefObject() { _InterlockedDecrement(&g_niObjectCount); }
    virtual void DeleteThis();  // 01

    // hot path: the engine counts references atomically, as NiRefObject::IncRefCount does
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        // hot path: the engine releases references atomically, as NiRefObject::DecRefCount does
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0) {
            DeleteThis();
        }
    }

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

template <class T>
class NiPointer
{
public:
    NiPointer() : _ptr(nullptr) {}
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }
    NiPointer& operator=(T* a_object)
    {
        if (_ptr != a_object) {
            if (a_object) {
                a_object->IncRefCount();
            }
            T* old = _ptr;
            _ptr = a_object;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class BSCubeMapCamera : public NiRefObject {};
class SharedReflectionObject : public NiRefObject {};
class BSWaterShaderMaterial;

// Only the slot the destructor calls is known; the slots before it are placeholders.
class ReflectionTarget
{
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Unk0B();
    virtual void Unk0C();
    virtual void Unk0D();
    virtual void Unk0E();
    virtual void Unk0F();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Destroy(std::uint32_t a_flags) noexcept;  // 15
};

// The element destructor is the function at 0x52ee00.
struct CubeMapSide
{
    ~CubeMapSide();

    std::uint64_t unk00;
};

class TESWaterReflections : public NiRefObject
{
public:
    ~TESWaterReflections() override;  // compared: 0x5281e0

    std::uint32_t flags;                           // 10
    float reflectPlane[4];                         // 14
    std::uint32_t unk24;                           // 24
    NiPointer<BSCubeMapCamera> cubeMapCamera;      // 28
    NiPointer<SharedReflectionObject> unk30;       // 30
    ReflectionTarget* unk38;                       // 38
    BSWaterShaderMaterial* waterMaterial;          // 40
    float unk48;                                   // 48
    CubeMapSide cubeMapSides[6];                   // 50
    std::uint8_t unk80[8];                         // 80
};
static_assert(sizeof(TESWaterReflections) == 0x88, "TESWaterReflections size");
