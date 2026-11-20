// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiProperty; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiExtraDataList.h"
#include "NiPointer_NiTimeController_4d1e262c.h"
struct NiProperty__VFTable;
struct NiProperty {
    NiProperty__VFTable* vftable_NiProperty_0;
    char _pad_8[8];
    BSFixedString Name_10;
    NiPointer_NiTimeController_4d1e262c TimeControllers_18;
    NiExtraDataList ExtraList_20;
};
static_assert(sizeof(NiProperty) == 48, "NiProperty layout differs from the PDB");
