// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GameData; size 0x4
#pragma once
struct GameData {
    unsigned short knownEffectFlags;
    unsigned short playerUses;
};
static_assert(sizeof(GameData) == 4, "GameData layout differs from the PDB");
