// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky, Sky::~Sky, Sky::root, Sky::moonsRoot, Sky::auroraRoot, Sky::auroraModel, Sky::atmosphere, Sky::stars, Sky::sun, Sky::clouds, Sky::masser, Sky::secunda, Sky::precip, Sky::currentReferenceEffect, Sky::lastReferenceEffect, Sky::effectController, Sky::storedCloudTextures, Sky::storedWorldMapCloudTextures, Sky::skyStaticRefData, BSMultiBoundNode, NiNode, Atmosphere, Stars, Sun, Clouds, Moon, Precipitation, ReferenceEffect, SkyEffectController, NiTexture, SkyStaticRefData, NiPointer, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer::_ptr, NiRefObject::DeleteThis, BSTArray, BSTArrayHeapAllocator, BSTArrayBase, BSTArrayHeapAllocator::data, BSTArrayHeapAllocator::capacity, BSTArrayBase::size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AuroraModelHandle, SkyStaticRefArray, BSMultiBoundNodeSub, Clear, Elements, Function20c650, VFunc00, VFunc38, Function418580, Function4199A0, Function418E10, IncRefCount, DecRefCount, m_uiRefCount, unk00, unk0C, unk10, unk28, unk30, unkA8, BSTArrayHeapAllocator::Release: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // Reference count is incremented atomically across threads.
        _InterlockedIncrement(&m_uiRefCount);
    }

    void DecRefCount()
    {
        // Reference count is decremented atomically across threads.
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0)
        {
            DeleteThis();
        }
    }

    long m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

template <class T>
class NiPointer
{
public:
    NiPointer() : _ptr(nullptr) {}
    ~NiPointer()
    {
        if (_ptr)
        {
            _ptr->DecRefCount();
        }
    }

    NiPointer& operator=(T* a_object)
    {
        if (_ptr != a_object)
        {
            if (a_object)
            {
                a_object->IncRefCount();
            }
            T* old = _ptr;
            _ptr = a_object;
            if (old)
            {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class BSTArrayHeapAllocator
{
public:
    ~BSTArrayHeapAllocator();
    void Release();

    void* data;              // 00
    std::uint32_t capacity;  // 08
};

class BSTArrayBase
{
public:
    ~BSTArrayBase();

    std::uint32_t size;  // 00
};

template <class T>
class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase
{
public:
    ~BSTArray();

    void Clear()
    {
        if (data)
        {
            if (size)
            {
                T* elems = static_cast<T*>(data);
                std::size_t n = size;
                do
                {
                    elems->~T();
                    ++elems;
                } while (--n);
            }
            Release();
            size = 0;
        }
    }

    T* Elements() { return static_cast<T*>(data); }
};

class SkyStaticRefArray : public BSTArrayHeapAllocator, public BSTArrayBase
{
public:
    ~SkyStaticRefArray()
    {
        if (data)
        {
            Release();
            size = 0;
        }
    }
};

class BSMultiBoundNode;

class BSMultiBoundNodeSub
{
public:
    virtual void VFunc00();
    virtual void VFunc01();
    virtual void VFunc02();
    virtual void VFunc03();
    virtual void VFunc04();
    virtual void VFunc05();
    virtual void VFunc06();
    virtual void VFunc07();
    virtual void VFunc08();
    virtual void VFunc09();
    virtual void VFunc0A();
    virtual void VFunc0B();
    virtual void VFunc0C();
    virtual void VFunc0D();
    virtual void VFunc0E();
    virtual void VFunc0F();
    virtual void VFunc10();
    virtual void VFunc11();
    virtual void VFunc12();
    virtual void VFunc13();
    virtual void VFunc14();
    virtual void VFunc15();
    virtual void VFunc16();
    virtual void VFunc17();
    virtual void VFunc18();
    virtual void VFunc19();
    virtual void VFunc1A();
    virtual void VFunc1B();
    virtual void VFunc1C();
    virtual void VFunc1D();
    virtual void VFunc1E();
    virtual void VFunc1F();
    virtual void VFunc20();
    virtual void VFunc21();
    virtual void VFunc22();
    virtual void VFunc23();
    virtual void VFunc24();
    virtual void VFunc25();
    virtual void VFunc26();
    virtual void VFunc27();
    virtual void VFunc28();
    virtual void VFunc29();
    virtual void VFunc2A();
    virtual void VFunc2B();
    virtual void VFunc2C();
    virtual void VFunc2D();
    virtual void VFunc2E();
    virtual void VFunc2F();
    virtual void VFunc30();
    virtual void VFunc31();
    virtual void VFunc32();
    virtual void VFunc33();
    virtual void VFunc34();
    virtual void VFunc35();
    virtual void VFunc36();
    virtual void VFunc37();
    virtual void VFunc38(BSMultiBoundNode* a_child);  // +0x1C0
};

class BSMultiBoundNode : public NiRefObject
{
public:
    std::uint8_t unk10[0x30 - 0x10];
    BSMultiBoundNodeSub* unk30;  // 30
};
static_assert(offsetof(BSMultiBoundNode, unk30) == 0x30, "BSMultiBoundNode unk30 offset");

class NiNode : public NiRefObject
{};

class NiTexture : public NiRefObject
{};

class ReferenceEffect : public NiRefObject
{};

class Atmosphere
{
public:
    virtual ~Atmosphere();
};

class Stars
{
public:
    virtual ~Stars();
};

class Sun
{
public:
    virtual ~Sun();
};

class Clouds
{
public:
    virtual ~Clouds();
};

class Moon
{
public:
    virtual ~Moon();
};

class Precipitation
{
public:
    virtual ~Precipitation();
};

class SkyEffectController
{
public:
    ~SkyEffectController();
    void* vftable;  // 00
};

struct AuroraModelHandle
{
    static void Function20c650(void* a_ptr) noexcept;
    ~AuroraModelHandle()
    {
        Function20c650(unk00);
    }
    void* unk00;
};

struct SkyStaticRefData
{
    std::uint64_t unk00;
};

class Sky
{
public:
    virtual ~Sky();  // compared: 0x411280
    void Function418580();
    void Function4199A0();
    void Function418E10(bool a_arg);

    NiPointer<BSMultiBoundNode> root;                         // 008
    NiPointer<NiNode> moonsRoot;                              // 010
    NiPointer<NiNode> auroraRoot;                             // 018
    AuroraModelHandle auroraModel;                            // 020
    std::uint8_t unk28[0x70 - 0x28];
    Atmosphere* atmosphere;                                   // 070
    Stars* stars;                                             // 078
    Sun* sun;                                                 // 080
    Clouds* clouds;                                           // 088
    Moon* masser;                                             // 090
    Moon* secunda;                                            // 098
    Precipitation* precip;                                    // 0A0
    std::uint8_t unkA8[0x268 - 0xA8];
    NiPointer<ReferenceEffect> currentReferenceEffect;        // 268
    NiPointer<ReferenceEffect> lastReferenceEffect;           // 270
    SkyEffectController effectController;                     // 278
    BSTArray<NiPointer<NiTexture>> storedCloudTextures;       // 280
    BSTArray<NiPointer<NiTexture>> storedWorldMapCloudTextures; // 298
    SkyStaticRefArray skyStaticRefData;                       // 2B0
};
static_assert(sizeof(Sky) == 0x2C8, "Sky size");
static_assert(offsetof(Sky, precip) == 0xA0, "Sky precip offset");
static_assert(offsetof(Sky, skyStaticRefData) == 0x2B0, "Sky skyStaticRefData offset");
