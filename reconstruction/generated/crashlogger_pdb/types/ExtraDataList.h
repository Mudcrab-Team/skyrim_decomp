// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDataList; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSReadWriteLock.h"
#include "BaseExtraList_5f76e5cb.h"
struct ExtraDataList {
    BaseExtraList_5f76e5cb _extraData;
    BSReadWriteLock _lock;
};
static_assert(sizeof(ExtraDataList) == 32, "ExtraDataList layout differs from the PDB");
