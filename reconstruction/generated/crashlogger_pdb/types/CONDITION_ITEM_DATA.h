// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CONDITION_ITEM_DATA; size 0x30
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "FUNCTION_DATA.h"
#include "GlobalOrFloat.h"
struct CONDITION_ITEM_DATA {
    GlobalOrFloat comparisonValue;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 runOnRef;
    unsigned int dataID;
    FUNCTION_DATA functionData;
    unsigned char flags_raw;
    unsigned char object;  // CONDITIONITEMOBJECT in the PDB is wider than this slot
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(CONDITION_ITEM_DATA) == 48, "CONDITION_ITEM_DATA layout differs from the PDB");
