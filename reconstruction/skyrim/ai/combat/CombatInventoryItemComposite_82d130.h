// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CombatInventoryItemComposite, CombatInventoryItemComposite::sub_14077DF10: CRASHLOGGER_PDB(59818@2026.10.24)
// InventoryItemForm, FormatPairDescription, gCompositeFormat, primaryItem, secondaryItem, unknown00, unknown18: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

void FormatPairDescription(char* a_buf, std::size_t a_size, const char* a_fmt, ...);
extern const char gCompositeFormat[];

class InventoryItemForm
{
public:
    virtual ~InventoryItemForm();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual const char* GetEditorID() const;  // slot 32 (+0x190)
};

class CombatInventoryItemComposite
{
public:
    void sub_14077DF10(char* a_buf, std::uint32_t a_size);  // compared: 0x82d130

    std::uint8_t unknown00[0x10];
    InventoryItemForm* primaryItem;    // 10
    std::uint8_t unknown18[0x18];      // 18
    InventoryItemForm* secondaryItem;  // 30
};
static_assert(offsetof(CombatInventoryItemComposite, primaryItem) == 0x10, "primaryItem offset");
static_assert(offsetof(CombatInventoryItemComposite, secondaryItem) == 0x30, "secondaryItem offset");
