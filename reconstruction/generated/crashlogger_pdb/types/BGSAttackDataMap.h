// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAttackDataMap; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_ab896b1b.h"
#include "NiRefObject.h"
struct TESRace_e57679c0;
struct BGSAttackDataMap {
    NiRefObject _base;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_ab896b1b attackDataMap;
    TESRace_e57679c0* defaultDataRace;
};
static_assert(sizeof(BGSAttackDataMap) == 72, "BGSAttackDataMap layout differs from the PDB");
