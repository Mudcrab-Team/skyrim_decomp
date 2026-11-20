// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSVoiceType; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "TESForm.h"
#include "VOICE_TYPE_DATA.h"
struct BGSVoiceType {
    TESForm _base;
    VOICE_TYPE_DATA data;
    unsigned char pad21;
    unsigned short pad22;
    unsigned short pad24;
    unsigned char undefined_26[2];
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
};
static_assert(sizeof(BGSVoiceType) == 56, "BGSVoiceType layout differs from the PDB");
