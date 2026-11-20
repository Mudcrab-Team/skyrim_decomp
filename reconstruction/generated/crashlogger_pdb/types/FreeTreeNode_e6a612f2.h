// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FreeTreeNode; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "Block_90f38ad6.h"
struct FreeTreeNode_e6a612f2 {
    Block_90f38ad6 Block_00;
    FreeTreeNode_e6a612f2** root_10;
    FreeTreeNode_e6a612f2* leftNode_18;
    FreeTreeNode_e6a612f2* rightNode_20;
    unsigned long long parentAndBlack;
};
static_assert(sizeof(FreeTreeNode_e6a612f2) == 48, "FreeTreeNode_e6a612f2 layout differs from the PDB");
