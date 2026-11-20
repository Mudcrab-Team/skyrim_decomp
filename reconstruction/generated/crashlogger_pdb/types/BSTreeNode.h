// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTreeNode; size 0x1b8
#pragma once

#include "BSLeafAnimNode.h"
struct BSTreeNode {
    BSLeafAnimNode _base;
    unsigned char unk170[72];
};
static_assert(sizeof(BSTreeNode) == 440, "BSTreeNode layout differs from the PDB");
