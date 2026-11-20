// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDataList; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BSReadWriteLock.h"
struct ExtraDataList_a372ab6e {
    unsigned char _extraData[16];  // BaseExtraList is 24 bytes in the PDB, more than this slot
    BSReadWriteLock _lock;
};
static_assert(sizeof(ExtraDataList_a372ab6e) == 24, "ExtraDataList_a372ab6e layout differs from the PDB");
