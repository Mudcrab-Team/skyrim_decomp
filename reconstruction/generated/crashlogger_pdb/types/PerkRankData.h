// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PerkRankData; size 0x10
#pragma once

struct BGSPerk_dfc65d7f;
struct PerkRankData {
    BGSPerk_dfc65d7f* perk;
    unsigned char currentRank;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(PerkRankData) == 16, "PerkRankData layout differs from the PDB");
