// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSExtraData__VFTable; size 0x18
#pragma once

struct BSExtraData;
struct BSExtraData__VFTable {
    unsigned long long*(*dtor_0)(BSExtraData* , char);
    int (*GetExtraDataId_8)(void);
    char (*IsEqual_10)(void);
};
static_assert(sizeof(BSExtraData__VFTable) == 24, "BSExtraData__VFTable layout differs from the PDB");
