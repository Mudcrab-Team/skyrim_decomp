// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction__CrimeDataValues; size 0x14
#pragma once
struct TESFaction__CrimeDataValues {
    bool Arrest_0;
    bool AttackOnSight_1;
    unsigned short MurderCrimeGold_2;
    unsigned short AssaultCrimeGold_4;
    unsigned short TrespassCrimeGold_6;
    unsigned short PickpocketCrimeGold_8;
    char _pad_A[2];
    float StealCrimeGoldMult_C;
    unsigned short EscapeCrimeGold_10;
    unsigned short WerewolfCrimeGold_12;
};
static_assert(sizeof(TESFaction__CrimeDataValues) == 20, "TESFaction__CrimeDataValues layout differs from the PDB");
