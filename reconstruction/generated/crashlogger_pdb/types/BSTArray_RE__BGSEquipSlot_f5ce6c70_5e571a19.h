// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BGSEquipSlot *>; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BGSEquipSlot;
struct BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19 {
    BGSEquipSlot** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19) == 24, "BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19 layout differs from the PDB");
