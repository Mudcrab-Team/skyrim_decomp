// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterDisplacement, TESWaterDisplacement::waterType, TESWaterDisplacement::waterHeight, TESWaterDisplacement::unk1C, TESWaterDisplacement::flags, TESWaterDisplacement::displacementGeometry, TESWaterSystem, TESWaterSystem::waterRoot, NiNode::DetachChild: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets and virtual slot 38
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer, NiNode, NiAVObject, TESWaterForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches, the earlier virtual slots are placeholders
// g_waterSystemSingleton: GUESS(low); the global the destructor reads
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

class NiAVObject : public NiRefObject {};
class TESWaterForm;

// Only slot 38 is called; the slots before it are placeholders.
class NiNode
{
public:
    virtual ~NiNode();
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
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1A();
    virtual void Unk1B();
    virtual void Unk1C();
    virtual void Unk1D();
    virtual void Unk1E();
    virtual void Unk1F();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2A();
    virtual void Unk2B();
    virtual void Unk2C();
    virtual void Unk2D();
    virtual void Unk2E();
    virtual void Unk2F();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void DetachChild(NiAVObject* a_child);  // 38
};

class TESWaterSystem
{
public:
    std::uint8_t unk00[0x90];
    NiNode* waterRoot;  // 90
};

extern TESWaterSystem* g_waterSystemSingleton;

class TESWaterDisplacement : public NiRefObject
{
public:
    TESWaterDisplacement();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x52ef20
    ~TESWaterDisplacement() override;

    TESWaterForm* waterType;                      // 10
    float waterHeight;                            // 18
    std::uint32_t unk1C;                          // 1C
    std::uint32_t flags;                          // 20
    NiPointer<NiAVObject> displacementGeometry;   // 28
};
static_assert(sizeof(TESWaterDisplacement) == 0x30, "TESWaterDisplacement size");
