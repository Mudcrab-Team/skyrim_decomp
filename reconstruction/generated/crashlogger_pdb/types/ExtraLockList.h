// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraLockList; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TESForm;
struct ExtraLockList {
    BSExtraData_4ca6af76 _base;
    TESForm* list;
};
static_assert(sizeof(ExtraLockList) == 24, "ExtraLockList layout differs from the PDB");
