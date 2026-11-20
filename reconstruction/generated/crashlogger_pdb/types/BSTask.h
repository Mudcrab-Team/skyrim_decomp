// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTask; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSTask_vtbl;
struct BSTask {
    BSTask_vtbl* __vftable;
    int refCount;
    unsigned int unk0C;
    unsigned char unk10[2];
    unsigned char priority;
    unsigned char unk13[5];
    int threadDepthMarker;
    unsigned char undefined_1c[4];
};
static_assert(sizeof(BSTask) == 32, "BSTask layout differs from the PDB");
