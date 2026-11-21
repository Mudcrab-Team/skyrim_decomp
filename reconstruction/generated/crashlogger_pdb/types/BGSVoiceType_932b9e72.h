// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSVoiceType; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "TESForm_4074aa87.h"
#include "VOICE_TYPE_DATA.h"
struct BGSVoiceType_932b9e72 {
    TESForm_4074aa87 _base;
    VOICE_TYPE_DATA data;
    unsigned char pad21;
    unsigned short pad22;
    unsigned short pad24;
    unsigned char undefined_26[2];
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
};
static_assert(sizeof(BGSVoiceType_932b9e72) == 56, "BGSVoiceType_932b9e72 layout differs from the PDB");
