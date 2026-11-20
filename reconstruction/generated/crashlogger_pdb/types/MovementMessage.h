// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementMessage; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct MovementMessage__VFTable;
struct MovementMessage {
    MovementMessage__VFTable* vftable_MovementMessage_0;
    int refCount_8;
    char _pad_C[4];
};
static_assert(sizeof(MovementMessage) == 16, "MovementMessage layout differs from the PDB");
