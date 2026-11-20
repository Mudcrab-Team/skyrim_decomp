// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Crime; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSReadWriteLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1.h"
struct BSSimpleList_Crime_74ebe029;
struct TESBoundObject;
struct TESFaction;
struct Crime {
    unsigned char undefined_0[4];
    int field4_0x4;
    unsigned long long unk08;
    BSSimpleList_Crime_74ebe029* crimes;
    TESBoundObject* object;
    unsigned long long unk20;
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1 actorsKnowOfCrime;
    unsigned long long unk40;
    unsigned long long unk48;
    unsigned long long unk50;
    TESFaction* fld58;
    TESFaction* crimeFaction;
    unsigned int unk68;
    BSReadWriteLock lock;
    unsigned int unk74;
};
static_assert(sizeof(Crime) == 120, "Crime layout differs from the PDB");
