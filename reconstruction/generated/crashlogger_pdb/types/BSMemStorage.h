// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMemStorage; size 0x30
#pragma once

#include "BSStorage.h"
struct Win32FileType;
struct BSMemStorage {
    BSStorage _base;
    Win32FileType* file;
    unsigned long long unk28;
};
static_assert(sizeof(BSMemStorage) == 48, "BSMemStorage layout differs from the PDB");
