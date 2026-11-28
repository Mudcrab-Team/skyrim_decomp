// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiPointer::~NiPointer, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCasterSummon: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject, NiPointer, CombatObject, CombatMagicCaster, CombatInventoryItemMagic, MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DecRef, inventoryItem, magicItem, ptr, unk0C: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class MagicItem;

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void DecRef()
    {
        // hot path: atomic reference release on smart pointer destruction
        if (_InterlockedExchangeAdd(&_refCount, -1) == 1)
        {
            DeleteThis();
        }
    }

    // volatile: intrusive reference count updated atomically across threads
    volatile long _refCount;  // 08
    std::uint32_t unk0C;      // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class CombatObject : public NiRefObject
{
public:
    CombatObject();
    ~CombatObject() override;
};
static_assert(sizeof(CombatObject) == 0x10, "CombatObject size");

class CombatInventoryItemMagic : public NiRefObject
{
};

template <class T>
class NiPointer
{
public:
    NiPointer() : ptr(nullptr) {}

    ~NiPointer()
    {
        if (ptr)
        {
            ptr->DecRef();
        }
    }

    T* ptr;  // 00
};

class CombatMagicCaster : public CombatObject
{
public:
    CombatMagicCaster();
    ~CombatMagicCaster() override {}

    NiPointer<CombatInventoryItemMagic> inventoryItem;  // 10
    MagicItem*                          magicItem;      // 18
};
static_assert(sizeof(CombatMagicCaster) == 0x20, "CombatMagicCaster size");

class CombatMagicCasterSummon : public CombatMagicCaster
{
public:
    CombatMagicCasterSummon();
    ~CombatMagicCasterSummon() override {}
};
static_assert(sizeof(CombatMagicCasterSummon) == 0x20, "CombatMagicCasterSummon size");
