// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellID; size 0x4
#pragma once
struct CellID {
    short y;
    short x;
};
static_assert(sizeof(CellID) == 4, "CellID layout differs from the PDB");
