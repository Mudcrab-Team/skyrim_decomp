// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction__RankData; size 0x20
#pragma once

#include "BSFixedString.h"
#include "TESTexture_fe82fffc.h"
struct TESFaction__RankData {
    BSFixedString MaleRankTitle_0;
    BSFixedString FemaleRankTitle_8;
    TESTexture_fe82fffc TextureInsignia_10;
};
static_assert(sizeof(TESFaction__RankData) == 32, "TESFaction__RankData layout differs from the PDB");
