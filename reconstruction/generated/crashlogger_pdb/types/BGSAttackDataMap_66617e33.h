// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAttackDataMap; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_ab896b1b.h"
#include "NiRefObject_f24a9221.h"
struct TESRace;
struct BGSAttackDataMap_66617e33 {
    NiRefObject_f24a9221 _base;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_ab896b1b attackDataMap;
    TESRace* defaultDataRace;
};
static_assert(sizeof(BGSAttackDataMap_66617e33) == 72, "BGSAttackDataMap_66617e33 layout differs from the PDB");
