// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatStyleFlightData; size 0x20
#pragma once
struct CombatStyleFlightData {
    float hoverChance;
    float diveBombChance;
    float groundAttackChance;
    float hoverTimeMult;
    float groundAttackTimeMult;
    float perchAttackChance;
    float perchAttackTimeMult;
    float flyingAttackChance;
};
static_assert(sizeof(CombatStyleFlightData) == 32, "CombatStyleFlightData layout differs from the PDB");
