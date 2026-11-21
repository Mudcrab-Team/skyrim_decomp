// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatStyleMeleeData; size 0x20
#pragma once
struct CombatStyleMeleeData {
    float attackIncapacitatedMult;
    float powerAttackIncapacitatedMult;
    float powerAttackBlockingMult;
    float bashMult;
    float bashRecoilMult;
    float bashAttackMult;
    float bashPowerAttackMult;
    float specialAttackMult;
};
static_assert(sizeof(CombatStyleMeleeData) == 32, "CombatStyleMeleeData layout differs from the PDB");
