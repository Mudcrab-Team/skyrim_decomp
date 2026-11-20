// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FreeBlock; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Block.h"
struct FreeBlock {
    Block _base;
    FreeBlock* left;
    FreeBlock* right;
};
static_assert(sizeof(FreeBlock) == 32, "FreeBlock layout differs from the PDB");
