// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatStyleGeneralData; size 0x28
#pragma once
struct CombatStyleGeneralData {
    float offensiveMult;
    float defensiveMult;
    float groupOffensiveMult;
    float meleeScoreMult;
    float magicScoreMult;
    float rangedScoreMult;
    float shoutScoreMult;
    float unarmedScoreMult;
    float staffScoreMult;
    float avoidThreatChance;
};
static_assert(sizeof(CombatStyleGeneralData) == 40, "CombatStyleGeneralData layout differs from the PDB");
