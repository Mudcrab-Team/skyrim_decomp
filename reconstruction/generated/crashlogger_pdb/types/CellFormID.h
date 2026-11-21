// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellFormID; size 0x4
#pragma once

#include "CellID.h"
struct CellFormID {
    CellID coordinates;
};
static_assert(sizeof(CellFormID) == 4, "CellFormID layout differs from the PDB");
