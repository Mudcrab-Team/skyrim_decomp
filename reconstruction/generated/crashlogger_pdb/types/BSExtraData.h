// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSExtraData; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSExtraData__VFTable;
struct BSExtraData {
    BSExtraData__VFTable* vftable_BSExtraData_0;
    BSExtraData* Next_8;
};
static_assert(sizeof(BSExtraData) == 16, "BSExtraData layout differs from the PDB");
