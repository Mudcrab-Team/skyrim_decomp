// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLeveledList; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
#include "SimpleArray_RE__LEVELED_OBJECT_665672a0.h"
struct TESGlobal;
struct TESLeveledList {
    BaseFormComponent _base;
    SimpleArray_RE__LEVELED_OBJECT_665672a0 entries;
    unsigned char chanceNone;
    unsigned char llFlags_raw;
    unsigned char numEntries;
    unsigned char unk13;
    unsigned int pad14;
    void* unk18;
    TESGlobal* chanceGlobal;
};
static_assert(sizeof(TESLeveledList) == 40, "TESLeveledList layout differs from the PDB");
