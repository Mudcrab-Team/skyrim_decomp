// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSKeyword; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "TESForm.h"
struct BGSKeyword {
    TESForm _base;
    BSFixedString_char_83b572b4 formEditorID;
};
static_assert(sizeof(BGSKeyword) == 40, "BGSKeyword layout differs from the PDB");
