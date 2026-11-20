// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraTextDisplayData; size 0x38
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSFixedString_char_83b572b4.h"
#include "DisplayDataType.h"
struct BGSMessage;
struct TESQuest_fe66f8e1;
struct ExtraTextDisplayData {
    BSExtraData_4ca6af76 _base;
    BSFixedString_char_83b572b4 displayName;
    BGSMessage* displayNameText;
    TESQuest_fe66f8e1* ownerQuest;
    DisplayDataType ownerInstance;
    float temperFactor;
    unsigned short customNameLength;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(ExtraTextDisplayData) == 56, "ExtraTextDisplayData layout differs from the PDB");
