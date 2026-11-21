// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GlobalOrFloat; size 0x8
#pragma once
struct GlobalOrFloat {
    float f;
    unsigned char undefined_4[4];
};
static_assert(sizeof(GlobalOrFloat) == 8, "GlobalOrFloat layout differs from the PDB");
