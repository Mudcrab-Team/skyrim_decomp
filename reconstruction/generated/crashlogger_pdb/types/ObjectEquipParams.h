// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectEquipParams; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BGSEquipSlot_15bd99b3;
struct ExtraDataList;
struct ObjectEquipParams {
    ExtraDataList* extraDataList;
    int count;
    unsigned int pad0C;
    BGSEquipSlot_15bd99b3* equipSlot;
    void* unk18;
    bool playEquipSounds;
    bool forceEquip;
    bool showMessage;
    bool unk23;
    bool unk24;
    unsigned char pad25;
    unsigned short pad26;
};
static_assert(sizeof(ObjectEquipParams) == 40, "ObjectEquipParams layout differs from the PDB");
