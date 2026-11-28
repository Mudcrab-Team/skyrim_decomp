// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: reconstruction from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryItemPtr::~InventoryItemPtr, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// CombatMagicCaster, CombatObject, inventoryItem, magicItem: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatInventoryItemMagicRef, InventoryItemPtr, DeleteThis, refCount, unknown08: GUESS(low)
#pragma once

#include <intrin.h>
#include <cstdint>

class CombatInventoryItemMagicRef
{
public:
    virtual ~CombatInventoryItemMagicRef();
    virtual void DeleteThis();  // slot 01 (+0x08)

    long refCount;
    std::uint32_t reserved0C;
};

struct InventoryItemPtr
{
    ~InventoryItemPtr()
    {
        CombatInventoryItemMagicRef* obj = ptr;
        if (obj) {
            // atomic reference decrement before virtual deletion
            if (_InterlockedExchangeAdd(&obj->refCount, -1) == 1) {
                obj->DeleteThis();
            }
        }
    }

    CombatInventoryItemMagicRef* ptr;
};

class CombatObject
{
public:
    virtual ~CombatObject();

    std::uint64_t unknown08;
};
static_assert(sizeof(CombatObject) == 0x10, "CombatObject size");

class CombatMagicCaster : public CombatObject
{
public:
    CombatMagicCaster();
    ~CombatMagicCaster() override;  // deleting dtor compared: 0x84d930

    InventoryItemPtr inventoryItem;  // 10
    void* magicItem;                 // 18
};
static_assert(sizeof(CombatMagicCaster) == 0x20, "CombatMagicCaster size");
