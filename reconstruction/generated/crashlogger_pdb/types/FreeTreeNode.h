// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FreeTreeNode; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Block.h"
struct FreeTreeNode {
    Block _base;
    FreeTreeNode** root;
    FreeTreeNode* leftNode;
    FreeTreeNode* rightNode;
    unsigned long long parentAndBlack;
};
static_assert(sizeof(FreeTreeNode) == 48, "FreeTreeNode layout differs from the PDB");
