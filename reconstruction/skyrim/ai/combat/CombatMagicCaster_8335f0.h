// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:145
// CombatMagicCaster, CombatMagicCaster::LoadGame, CombatInventoryItemMagic, GetMagic, BGSLoadFormBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatMagicCaster, inventoryItem, magicItem: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatObject, CombatObject::LoadGame, CombatObject::Load, DeleteThis, m_uiRefCount, CombatInventoryItemMagicRef: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class BGSLoadFormBuffer;
class MagicItem;

class CombatObject
{
public:
    virtual ~CombatObject();
    virtual void DeleteThis();
    void LoadGame(BGSLoadFormBuffer* a_buffer);
    static CombatObject* Load(BGSLoadFormBuffer* a_buffer);

    std::uint32_t m_uiRefCount;
};

class CombatInventoryItemMagic : public CombatObject
{
public:
    // Slots 2 to 21 are not used here; only the slot the caster calls is named.
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk20();
    virtual void unk21();
    virtual MagicItem* GetMagic();  // 22
};

// Reference-counting pointer: retain the new object, release the old one, delete at zero.
struct CombatInventoryItemMagicRef
{
    CombatInventoryItemMagic* m_pObject;

    CombatInventoryItemMagicRef& operator=(CombatInventoryItemMagic* a_new)
    {
        CombatInventoryItemMagic* old = m_pObject;
        if (old != a_new) {
            if (a_new) {
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_new->m_uiRefCount));  // atomic: refcounts are shared across threads
            }
            m_pObject = a_new;
            if (old) {
                // atomic: refcounts are shared across threads
                std::uint32_t count = _InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount));
                if (count == 0) {
                    old->DeleteThis();
                }
            }
        }
        return *this;
    }
};

class CombatMagicCaster : public CombatObject
{
public:
    void LoadGame(BGSLoadFormBuffer* a_buffer);  // compared: 0x8335f0

    CombatInventoryItemMagicRef inventoryItem;  // 10
    MagicItem* magicItem;                       // 18
};
static_assert(sizeof(CombatMagicCaster) == 0x20, "CombatMagicCaster size");
