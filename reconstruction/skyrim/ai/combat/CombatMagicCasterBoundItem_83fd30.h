// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatMagicCasterBoundItem, CombatMagicCaster, CombatObject, CombatInventoryItemMagic, MagicItem: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer83fd30, refCount, ptr, inventoryItem, magicItem, DeleteThis: GUESS(low)
// 0x83fd30 CombatMagicCasterBoundItem::~CombatMagicCasterBoundItem
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
struct NiPointer83fd30
{
    ~NiPointer83fd30()
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

    NiPointer83fd30<CombatInventoryItemMagic> inventoryItem;
    MagicItem* magicItem;
};

class CombatMagicCasterBoundItem : public CombatMagicCaster
{
public:
    CombatMagicCasterBoundItem();
    ~CombatMagicCasterBoundItem() override;
};

static_assert(offsetof(CombatMagicCaster, inventoryItem) == 0x10, "inventoryItem offset");
static_assert(sizeof(CombatMagicCasterBoundItem) == 0x20, "CombatMagicCasterBoundItem size");
