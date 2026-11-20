// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventory; size 0x1c8
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimer.h"
#include "BSTArray_RE__CombatEquippedItem_4bf3f4a0_db612782.h"
#include "BSTArray_RE__TESForm_7f041170_964e9a4e.h"
#include "CombatEquipment.h"
struct BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19;
struct CombatController_f906bf3b;
struct CombatInventory_e4d1e3ab {
    CombatController_f906bf3b* parentController;
    unsigned char inventoryItems_raw[168];
    BSTArray_RE__TESForm_7f041170_964e9a4e unk0B0;
    BSTArray_RE__TESForm_7f041170_964e9a4e unk0C8;
    BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19* raceEquipSlots;
    unsigned long long unk0E8;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned long long unk100;
    unsigned long long unk108;
    unsigned long long unk110;
    CombatEquipment unk118;
    CombatEquipment unk148;
    BSTArray_RE__CombatEquippedItem_4bf3f4a0_db612782 equippedItems;
    int unk190;
    AITimer equippedTimer;
    float unk19C;
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
static_assert(sizeof(CombatInventory_e4d1e3ab) == 456, "CombatInventory_e4d1e3ab layout differs from the PDB");
