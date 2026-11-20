// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSExtraDataList; size 0x18
#pragma once

#include "MutexRW.h"
struct BSExtraData;
struct BSExtraDataList__PresenceBitfield;
struct BSExtraDataList {
    BSExtraData* First_0;
    BSExtraDataList__PresenceBitfield* Mask_8;
    MutexRW Lock_10;
};
static_assert(sizeof(BSExtraDataList) == 24, "BSExtraDataList layout differs from the PDB");
