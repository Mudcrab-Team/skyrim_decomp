// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicType; size 0x78
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSIMusicType_8f0bc6cf.h"
#include "TESForm.h"
struct BGSMusicType_01bbbee6 {
    TESForm _base;
    BSIMusicType_8f0bc6cf _base_BSIMusicType;
    BSFixedString_char_83b572b4 formEditorID;
};
static_assert(sizeof(BGSMusicType_01bbbee6) == 120, "BGSMusicType_01bbbee6 layout differs from the PDB");
