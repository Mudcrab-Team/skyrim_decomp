// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DetectionEvent; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3.h"
struct DetectionEvent_59502287 {
    unsigned int actionValue;
    NiPoint3 location;
    AITimeStamp timeStamp;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 ref;
};
static_assert(sizeof(DetectionEvent_59502287) == 24, "DetectionEvent_59502287 layout differs from the PDB");
