// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IStore; size 0x20
#pragma once

#include "BSStorage.h"
struct IStore {
    BSStorage _base;
};
static_assert(sizeof(IStore) == 32, "IStore layout differs from the PDB");
