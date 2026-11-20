// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBodyPart; size 0xf0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "PART_DATA_acdc582b.h"
#include "TESModel.h"
#include "TESModelPSA.h"
struct BGSBodyPart {
    unsigned char nodeName_raw[8];
    unsigned char targetName_raw[8];
    unsigned char hitReactionVariablePrefix_raw[8];
    unsigned char partName_raw[8];
    unsigned char goreObjectName_raw[8];
    TESModel explosionSpecialDebris;
    TESModelPSA poseMatching;
    PART_DATA_acdc582b data;
};
static_assert(sizeof(BGSBodyPart) == 240, "BGSBodyPart layout differs from the PDB");
