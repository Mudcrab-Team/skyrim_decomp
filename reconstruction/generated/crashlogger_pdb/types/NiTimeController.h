// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTimeController; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiObjectNET_5d8e1bd4;
struct NiTimeController {
    unsigned char undefined_0[16];
    unsigned short flags;  // Flag in the PDB is wider than this slot
    unsigned short pad12;
    float frequency;
    float Phase_18;
    float LoKeyTime_1C;
    float HiKeyTime_20;
    float StartTime_24;
    float lastTime;
    float weightedLastTime;
    float ScaledTime_30;
    unsigned char undefined_34[4];
    NiObjectNET_5d8e1bd4* Target_38;
    NiTimeController* NextController_40;
};
static_assert(sizeof(NiTimeController) == 72, "NiTimeController layout differs from the PDB");
