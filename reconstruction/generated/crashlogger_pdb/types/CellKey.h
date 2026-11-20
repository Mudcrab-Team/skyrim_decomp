// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellKey; size 0x4
#pragma once
struct CellKey {
    unsigned int raw;
};
static_assert(sizeof(CellKey) == 4, "CellKey layout differs from the PDB");
