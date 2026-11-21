// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletData; size 0x10
#pragma once

struct BSTaskletData_vtbl;
struct BSTaskletData {
    BSTaskletData_vtbl* __vftable;
    unsigned char undefined_8[8];
};
static_assert(sizeof(BSTaskletData) == 16, "BSTaskletData layout differs from the PDB");
