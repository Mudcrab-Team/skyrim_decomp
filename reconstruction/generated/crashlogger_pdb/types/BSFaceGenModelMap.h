// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenModelMap; size 0x40
#pragma once

#include "BSReadWriteLock.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_616492d3.h"
struct BSFaceGenModelMap {
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_616492d3 map;
    BSReadWriteLock lock;
    bool hasFaceGenData;
    unsigned char undefined_39[7];
};
static_assert(sizeof(BSFaceGenModelMap) == 64, "BSFaceGenModelMap layout differs from the PDB");
