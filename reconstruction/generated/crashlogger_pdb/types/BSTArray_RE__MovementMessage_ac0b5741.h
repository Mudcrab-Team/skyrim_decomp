// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::MovementMessage *>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct MovementMessage_562a17f0;
struct BSTArray_RE__MovementMessage_ac0b5741 {
    MovementMessage_562a17f0** _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_RE__MovementMessage_ac0b5741) == 24, "BSTArray_RE__MovementMessage_ac0b5741 layout differs from the PDB");
