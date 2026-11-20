// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FACTION_CRIME_DATA_VALUES; size 0x14
#pragma once
struct FACTION_CRIME_DATA_VALUES {
    bool arrest;
    bool attackOnSight;
    unsigned short murderCrimeGold;
    unsigned short assaultCrimeGold;
    unsigned short trespassCrimeGold;
    unsigned short pickpocketCrimeGold;
    unsigned short pad0A;
    float stealCrimeGoldMult;
    unsigned short escapeCrimeGold;
    unsigned short werewolfCrimeGold;
};
static_assert(sizeof(FACTION_CRIME_DATA_VALUES) == 20, "FACTION_CRIME_DATA_VALUES layout differs from the PDB");
