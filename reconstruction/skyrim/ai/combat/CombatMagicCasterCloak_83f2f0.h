// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatMagicCasterCloak, CombatMagicCaster, CombatObject, CombatInventoryItemMagic, MagicItem: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer83f2f0, refCount, ptr, inventoryItem, magicItem, DeleteThis: GUESS(low)
// 0x83f2f0 CombatMagicCasterCloak::~CombatMagicCasterCloak
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class MagicItem;

class CombatInventoryItemMagic
{
public:
    virtual ~CombatInventoryItemMagic();
    virtual void DeleteThis();

    long refCount;
};

template <class T>
struct NiPointer83f2f0
{
    ~NiPointer83f2f0()
    {
        T* old = ptr;
        // intrinsic: atomic refcount decrement on smart pointer release
        if (old && _InterlockedExchangeAdd(&old->refCount, -1) == 1) {
            old->DeleteThis();
        }
    }

    T* ptr;
};

class CombatObject
{
public:
    virtual ~CombatObject();

    long refCount;
};

class CombatMagicCaster : public CombatObject
{
public:
    ~CombatMagicCaster() override {}

    NiPointer83f2f0<CombatInventoryItemMagic> inventoryItem;
    MagicItem* magicItem;
};

class CombatMagicCasterCloak : public CombatMagicCaster
{
public:
    CombatMagicCasterCloak();
    ~CombatMagicCasterCloak() override;
};

static_assert(offsetof(CombatMagicCaster, inventoryItem) == 0x10, "inventoryItem offset");
static_assert(sizeof(CombatMagicCasterCloak) == 0x20, "CombatMagicCasterCloak size");
