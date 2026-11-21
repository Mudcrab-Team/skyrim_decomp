// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MobIterOperator; size 0x10
#pragma once

struct MobIterOperator_vtbl;
struct MobIterOperator {
    MobIterOperator_vtbl* __vftable;
    unsigned char processType_raw[8];
};
static_assert(sizeof(MobIterOperator) == 16, "MobIterOperator layout differs from the PDB");
