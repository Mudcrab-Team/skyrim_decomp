// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Crime; size 0x78
// one of 2 different PDB types sharing this name
#pragma once

#include "BSReadWriteLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5.h"
struct TESFaction_fe5903c5;
struct TESForm;
struct Crime_833e31a6 {
    unsigned long long unk00;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 actorsKnowOfCrime;
    TESForm* owner;
    unsigned long long unk48;
    unsigned long long unk50;
    TESFaction_fe5903c5* unk58;
    TESFaction_fe5903c5* crimeFaction;
    unsigned int unk68;
    BSReadWriteLock lock;
    unsigned int unk74;
};
static_assert(sizeof(Crime_833e31a6) == 120, "Crime_833e31a6 layout differs from the PDB");
