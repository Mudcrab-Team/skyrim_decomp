// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction; size 0x100
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "BSSimpleList_RE__RANK_DATA_6deb2ff0.h"
#include "FACTION_CRIME_DATA.h"
#include "FACTION_DATA.h"
#include "FACTION_VENDOR_DATA.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESReactionForm.h"
struct RE__BSTScatterTable_RE__BSCRC32_RE__TESNPC_std__equal_to_RE__TESNPC_RE__BSTScatterTable_9a1b7755;
struct TESFaction_fe5903c5 {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESReactionForm _base_TESReactionForm;
    RE__BSTScatterTable_RE__BSCRC32_RE__TESNPC_std__equal_to_RE__TESNPC_RE__BSTScatterTable_9a1b7755* crimeGoldMap;
    FACTION_DATA data;
    unsigned int pad05C;
    FACTION_CRIME_DATA crimeData;
    FACTION_VENDOR_DATA vendorData;
    BSSimpleList_RE__RANK_DATA_6deb2ff0 rankData;
    int majorCrime;
    int minorCrime;
    AITimeStamp resistArrestTimeStamp;
    float pcEnemyFlagTimeStamp;
};
static_assert(sizeof(TESFaction_fe5903c5) == 256, "TESFaction_fe5903c5 layout differs from the PDB");
