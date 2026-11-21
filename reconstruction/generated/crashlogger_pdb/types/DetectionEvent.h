// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DetectionEvent; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3_a7124070.h"
struct DetectionEvent {
    unsigned int actionValue;
    NiPoint3_a7124070 location;
    AITimeStamp timeStamp;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 ref;
};
static_assert(sizeof(DetectionEvent) == 24, "DetectionEvent layout differs from the PDB");
