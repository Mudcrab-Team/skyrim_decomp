// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTask; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BSTask__VFTable;
struct BSTask_b2e18bcd {
    BSTask__VFTable* vtable;
    int refCount;
    unsigned int unk0C;
    unsigned char unk10[2];
    unsigned char priority;
    unsigned char unk13[5];
};
static_assert(sizeof(BSTask_b2e18bcd) == 24, "BSTask_b2e18bcd layout differs from the PDB");
