// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::CombatMember>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct CombatMember;
struct BSTArray_RE__CombatMember_a3db0469 {
    CombatMember* _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__CombatMember_a3db0469) == 24, "BSTArray_RE__CombatMember_a3db0469 layout differs from the PDB");
