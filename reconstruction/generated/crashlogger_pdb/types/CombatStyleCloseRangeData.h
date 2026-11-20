// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatStyleCloseRangeData; size 0x10
#pragma once
struct CombatStyleCloseRangeData {
    float circleMult;
    float fallbackMult;
    float flankDistanceMult;
    float stalkTimeMult;
};
static_assert(sizeof(CombatStyleCloseRangeData) == 16, "CombatStyleCloseRangeData layout differs from the PDB");
