// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectEquipParams; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

struct BGSEquipSlot;
struct BSExtraDataList;
struct ObjectEquipParams_3100cf69 {
    BSExtraDataList* ExtraDataList_0;
    int Count_8;
    char _pad_C[4];
    BGSEquipSlot* EquipSlot_10;
    char _pad_18[8];
    bool PlayEquipSounds_20;
    bool ForceEquip_21;
    bool ShowMessage_22;
    char _pad_23[5];
};
static_assert(sizeof(ObjectEquipParams_3100cf69) == 40, "ObjectEquipParams_3100cf69 layout differs from the PDB");
