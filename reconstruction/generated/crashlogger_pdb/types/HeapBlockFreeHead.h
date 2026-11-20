// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapBlockFreeHead; size 0x40
#pragma once

#include "HeapBlock.h"
struct HeapBlockFreeHead {
    HeapBlock _base;
    unsigned long long parentPtrAndBlackBit;
    HeapBlockFreeHead* leftChild;
    HeapBlockFreeHead* rightChild;
    HeapBlockFreeHead** root;
};
static_assert(sizeof(HeapBlockFreeHead) == 64, "HeapBlockFreeHead layout differs from the PDB");
