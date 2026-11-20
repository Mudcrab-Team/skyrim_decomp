// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAlphaProperty; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiExtraDataList.h"
#include "NiPointer_NiTimeController_4d1e262c.h"
struct NiAlphaProperty__VFTable;
struct NiAlphaProperty {
    NiAlphaProperty__VFTable* vftable_NiAlphaProperty_0;
    char _pad_8[8];
    BSFixedString Name_10;
    NiPointer_NiTimeController_4d1e262c TimeControllers_18;
    NiExtraDataList ExtraList_20;
    char _pad_30[8];
};
static_assert(sizeof(NiAlphaProperty) == 56, "NiAlphaProperty layout differs from the PDB");
