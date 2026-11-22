// Source exposure: mixed (local binary analysis and public names). Build sse-steam-1-7-104.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. GetType is synthesized from the bounded leaf template; GetEquipType is read from the listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMagic: EXE_RTTI
// CombatInventoryItemMagic::GetType, ::GetEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG returns the TYPE enumeration, kept as a 32-bit integer here
// CombatInventoryItemMagic::GetEquipType: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// CombatInventoryItemMagic::minRange, ::maxRange, ::tacticalDuration, ::power, ::currentAV, ::effect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatInventoryItem, CombatInventoryItemSlot, BGSEquipSlot, BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatInventoryItem::item, ::itemScore, ::unk1C, ::itemSlot, CombatInventoryItemSlot::equipSlot, ::slot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEquipSlot::parentSlots, ::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArray::_data, ::operator[]: GUESS(low); the data pointer at +0
// BGSEquipSlot::kUseAllParents: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// padding, reserved slots, unknown: GUESS(low); placeholders for slots and members the compared code does not use
#pragma once
#include <cstdint>

class TESForm;
struct Effect;

template <class T>
class BSTArray
{
public:
    T& operator[](std::uint32_t a_index) const { return _data[a_index]; }

    T* _data;                    // 00
    std::uint32_t unknown08[4];  // 08
};

class BGSEquipSlot
{
public:
    enum Flag : std::uint32_t
    {
        kUseAllParents = 1 << 0
    };

    virtual ~BGSEquipSlot();
    std::uint8_t unknown08[0x18];         // 08
    BSTArray<BGSEquipSlot*> parentSlots;  // 20
    std::uint32_t flags;                  // 38
    std::uint32_t pad3C;                  // 3C
};
static_assert(sizeof(BGSEquipSlot) == 0x40, "BGSEquipSlot size");

class CombatInventoryItemSlot
{
public:
    BGSEquipSlot* equipSlot;  // 00
    std::uint32_t slot;       // 08
    std::uint32_t pad0C;      // 0C
};

class CombatInventoryItem
{
public:
    virtual ~CombatInventoryItem();                    // 00
    virtual void reservedSlot01();                     // 01
    virtual void reservedSlot02();                     // 02
    virtual void reservedSlot03();                     // 03
    virtual void reservedSlot04();                     // 04
    virtual void reservedSlot05();                     // 05
    virtual void reservedSlot06();                     // 06
    virtual void reservedSlot07();                     // 07
    virtual void reservedSlot08();                     // 08
    virtual std::uint32_t GetType() const;             // 09

    std::uint8_t unknown08[8];                         // 08
    TESForm* item;                                     // 10
    float itemScore;                                   // 18
    std::uint32_t unk1C;                               // 1C
    CombatInventoryItemSlot itemSlot;                  // 20
};
static_assert(sizeof(CombatInventoryItem) == 0x30, "CombatInventoryItem size");

class CombatInventoryItemMagic : public CombatInventoryItem
{
public:
    std::uint32_t GetType() const override;
    virtual std::uint32_t GetEquipType(BGSEquipSlot* a_slot) const;  // 0A

    float minRange;          // 30
    float maxRange;          // 34
    float tacticalDuration;  // 38
    float power;             // 3C
    float currentAV;         // 40
    std::uint32_t pad44;     // 44
    Effect* effect;          // 48
};
static_assert(sizeof(CombatInventoryItemMagic) == 0x50, "CombatInventoryItemMagic size");
