// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiInterpController; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiInterpController__VFTable;
struct NiObjectNET_5d8e1bd4;
struct NiTimeController;
struct NiInterpController {
    NiInterpController__VFTable* vftable_NiInterpController_0;
    char _pad_8[8];
    unsigned short IFlags_10;
    char _pad_12[2];
    float Frequency_14;
    float Phase_18;
    float LoKeyTime_1C;
    float HiKeyTime_20;
    float StartTime_24;
    float LastTime_28;
    float WeightedLastTime_2C;
    float ScaledTime_30;
    char _pad_34[4];
    NiObjectNET_5d8e1bd4* Target_38;
    NiTimeController* NextController_40;
};
static_assert(sizeof(NiInterpController) == 72, "NiInterpController layout differs from the PDB");
