// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GString; size 0x8
#pragma once

#include "DataDescUnion.h"
struct GString {
    DataDescUnion _dataDesc;
};
static_assert(sizeof(GString) == 8, "GString layout differs from the PDB");
