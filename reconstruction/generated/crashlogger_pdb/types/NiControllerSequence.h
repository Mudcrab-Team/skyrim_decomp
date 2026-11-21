// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiControllerSequence; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "SimpleArray_RE__NiControllerSequence__InterpArrayItem_ae559d89.h"
struct NiControllerSequence__VFTable;
struct NiControllerSequence {
    NiControllerSequence__VFTable* vftable_NiControllerSequence_0;
    char _pad_8[8];
    BSFixedString Name_10;
    unsigned int arraySize;
    unsigned int arrayGrowBy;
    SimpleArray_RE__NiControllerSequence__InterpArrayItem_ae559d89 interpArray;
    unsigned char undefined_28[144];
};
static_assert(sizeof(NiControllerSequence) == 184, "NiControllerSequence layout differs from the PDB");
