// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::MovementMessage *>; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct MovementMessage;
struct BSTArray_RE__MovementMessage_ac0b5741_d03864fa {
    MovementMessage** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__MovementMessage_ac0b5741_d03864fa) == 24, "BSTArray_RE__MovementMessage_ac0b5741_d03864fa layout differs from the PDB");
