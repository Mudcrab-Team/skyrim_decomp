// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellData; size 0x8
#pragma once

struct INTERIOR_DATA;
struct CellData {
    INTERIOR_DATA* interior;
};
static_assert(sizeof(CellData) == 8, "CellData layout differs from the PDB");
