// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::CombatAimController *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct CombatAimController_af40e787;
struct BSTArray_RE__CombatAimController_755075ef {
    CombatAimController_af40e787** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__CombatAimController_755075ef) == 24, "BSTArray_RE__CombatAimController_755075ef layout differs from the PDB");
