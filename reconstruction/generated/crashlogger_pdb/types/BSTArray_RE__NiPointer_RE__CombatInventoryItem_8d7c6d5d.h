// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::NiPointer<RE::CombatInventoryItem>>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiPointer_RE__CombatInventoryItem_41fc5e39;
struct BSTArray_RE__NiPointer_RE__CombatInventoryItem_8d7c6d5d {
    NiPointer_RE__CombatInventoryItem_41fc5e39* _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_RE__NiPointer_RE__CombatInventoryItem_8d7c6d5d) == 24, "BSTArray_RE__NiPointer_RE__CombatInventoryItem_8d7c6d5d layout differs from the PDB");
