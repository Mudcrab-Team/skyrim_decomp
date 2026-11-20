// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadStorageWrapper; size 0x30
#pragma once

#include "BSMemStorage.h"
struct LoadStorageWrapper {
    BSMemStorage _base;
};
static_assert(sizeof(LoadStorageWrapper) == 48, "LoadStorageWrapper layout differs from the PDB");
