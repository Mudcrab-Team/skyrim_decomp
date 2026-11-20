// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBodyPart; size 0xf0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "PART_DATA.h"
#include "TESModelPSA_a8b10a90.h"
#include "TESModel_c52655e4.h"
struct BGSBodyPart_4f632c83 {
    BSFixedString_char_83b572b4 nodeName;
    BSFixedString_char_83b572b4 targetName;
    BSFixedString_char_83b572b4 hitReactionVariablePrefix;
    BSFixedString_char_83b572b4 partName;
    BSFixedString_char_83b572b4 goreObjectName;
    TESModel_c52655e4 explosionSpecialDebris;
    TESModelPSA_a8b10a90 poseMatching;
    PART_DATA data;
};
static_assert(sizeof(BGSBodyPart_4f632c83) == 240, "BGSBodyPart_4f632c83 layout differs from the PDB");
