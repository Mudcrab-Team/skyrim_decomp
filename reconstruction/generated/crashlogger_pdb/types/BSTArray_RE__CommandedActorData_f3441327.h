// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::CommandedActorData>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct CommandedActorData;
struct BSTArray_RE__CommandedActorData_f3441327 {
    CommandedActorData* _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_RE__CommandedActorData_f3441327) == 24, "BSTArray_RE__CommandedActorData_f3441327 layout differs from the PDB");
