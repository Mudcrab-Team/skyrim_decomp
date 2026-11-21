// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMemoryStore; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "IMemoryStoreBase.h"
struct IMemoryStore {
    IMemoryStoreBase _base;
};
static_assert(sizeof(IMemoryStore) == 8, "IMemoryStore layout differs from the PDB");
