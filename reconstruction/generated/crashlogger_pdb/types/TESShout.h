// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESShout; size 0xa8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLocalizedStringDL_8410e68a.h"
#include "BSFixedString.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESShout__WordData.h"
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSMenuDisplayObject__VFTable;
struct TESBoundObject;
struct TESDescription__VFTable;
struct TESFullName__VFTable;
struct TESShout__VFTable;
struct TESShout {
    TESShout__VFTable* vftable_TESShout_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    BGSMenuDisplayObject__VFTable* vftable_BGSMenuDisplayObject_30;
    TESBoundObject* MenuDisplayObject_38;
    BGSEquipType__VFTable* vftable_BGSEquipType_40;
    BGSEquipSlot* EquipSlot_48;
    TESDescription__VFTable* vftable_TESDescription_50;
    unsigned int FileOffset_58;
    BGSLocalizedStringDL_8410e68a DescriptionText_5C;
    TESShout__WordData Words_60[3];
};
static_assert(sizeof(TESShout) == 168, "TESShout layout differs from the PDB");
