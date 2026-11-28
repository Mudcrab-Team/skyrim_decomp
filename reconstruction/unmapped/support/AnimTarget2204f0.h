// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr2204f0::Reset and RefObject2204f0::DecRefCount, treated as adapted: shaped like NiPointer::reset and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/N/NiRefObject.cpp:28, MIT); AnimTarget2204f0::RefreshTargets also shaped like the target refresh loop in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:2753
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject2204f0, RefPtr2204f0, SceneNode2204f0, SceneHolder2204f0, TargetSlot2204f0, TargetEntry2204f0, AnimTarget2204f0, DeleteThis, DecRefCount, Reset, GetObjectByName, RefreshTargets, refCount, object, root, refObj, ptr10, flag18, name, count, slots, entries, holder, rootName, rootNode, gDefaultFlag2204f0: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

extern std::uint8_t gDefaultFlag2204f0;

class RefObject2204f0
{
public:
    virtual ~RefObject2204f0();
    virtual void DeleteThis();

    void DecRefCount()
    {
        // Atomic reference count decrement for shared object ownership.
        std::uint32_t count = _InterlockedDecrement(&refCount);
        if (count == 0)
        {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

class RefPtr2204f0
{
public:
    void Reset()
    {
        RefObject2204f0* old = object;
        if (old)
        {
            object = nullptr;
            old->DecRefCount();
        }
    }

    RefObject2204f0* object;  // 00
};

class SceneNode2204f0
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual SceneNode2204f0* GetObjectByName(const char** name);
};

struct SceneHolder2204f0
{
    std::uint8_t unk00[0xC0];  // 00
    SceneNode2204f0* root;     // C0
};

struct TargetSlot2204f0
{
    std::uint64_t unk00;     // 00
    RefPtr2204f0 refObj;     // 08
    void* ptr10;             // 10
    std::uint8_t flag18;     // 18
    std::uint8_t unk19[7];   // 19
};

static_assert(sizeof(TargetSlot2204f0) == 0x20, "TargetSlot2204f0 size");

struct TargetEntry2204f0
{
    const char* name;         // 00
    std::uint64_t unk08[4];   // 08
};

static_assert(sizeof(TargetEntry2204f0) == 0x28, "TargetEntry2204f0 size");

class AnimTarget2204f0
{
public:
    void RefreshTargets();

    std::uint8_t unk00[0x18];    // 00
    std::uint32_t count;         // 18
    TargetSlot2204f0* slots;     // 20
    TargetEntry2204f0* entries;  // 28
    std::uint8_t unk30[0x30];    // 30
    SceneHolder2204f0* holder;   // 60
    std::uint8_t unk68[0x20];    // 68
    const char* rootName;        // 88
    SceneNode2204f0* rootNode;   // 90
};
