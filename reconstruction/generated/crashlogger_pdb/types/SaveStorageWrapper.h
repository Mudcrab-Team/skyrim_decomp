// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SaveStorageWrapper; size 0x38
#pragma once

#include "BSMemStorage.h"
struct SaveStorageWrapper {
    BSMemStorage _base;
    unsigned long long unk30;
};
static_assert(sizeof(SaveStorageWrapper) == 56, "SaveStorageWrapper layout differs from the PDB");
