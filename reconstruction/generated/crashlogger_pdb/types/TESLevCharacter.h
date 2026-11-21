// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLevCharacter; size 0x90
#pragma once

#include "TESBoundAnimObject.h"
#include "TESLeveledList.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct TESLevCharacter {
    TESBoundAnimObject _base;
    TESLeveledList _base_TESLeveledList;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
};
static_assert(sizeof(TESLevCharacter) == 144, "TESLevCharacter layout differs from the PDB");
