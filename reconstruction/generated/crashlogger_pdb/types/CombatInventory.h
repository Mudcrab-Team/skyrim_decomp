// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventory; size 0x1c8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimer.h"
#include "BSTArray_RE__CombatEquippedItem_4bf3f4a0.h"
#include "BSTArray_RE__TESForm_7f041170.h"
#include "CombatEquipment_924a7417.h"
struct BSTArray_RE__BGSEquipSlot_f5ce6c70;
struct CombatController;
struct CombatInventory {
    CombatController* parentController;
    unsigned char inventoryItems_raw[168];
    BSTArray_RE__TESForm_7f041170 unk0B0;
    BSTArray_RE__TESForm_7f041170 unk0C8;
    BSTArray_RE__BGSEquipSlot_f5ce6c70* raceEquipSlots;
    unsigned long long unk0E8;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned long long unk100;
    unsigned long long unk108;
    unsigned long long unk110;
    CombatEquipment_924a7417 unk118;
    CombatEquipment_924a7417 unk148;
    BSTArray_RE__CombatEquippedItem_4bf3f4a0 equippedItems;
    int unk190;
    AITimer equippedTimer;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    float actorExtents;
    float actorCollisionExtents;
    float minimumEffectiveDistance;
    float maximumEffectiveDistance;
    float maximumRange;
    float optimalRange;
    float minimumRange;
    bool dirty;
    unsigned char undefined_1c5[3];
};
static_assert(sizeof(CombatInventory) == 456, "CombatInventory layout differs from the PDB");
