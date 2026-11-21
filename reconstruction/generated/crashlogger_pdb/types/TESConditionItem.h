// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESConditionItem; size 0x38
#pragma once

#include "CONDITION_ITEM_DATA.h"
struct TESConditionItem {
    TESConditionItem* next;
    CONDITION_ITEM_DATA data;
};
static_assert(sizeof(TESConditionItem) == 56, "TESConditionItem layout differs from the PDB");
