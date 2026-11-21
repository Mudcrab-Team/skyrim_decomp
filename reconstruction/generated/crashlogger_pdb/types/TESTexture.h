// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESTexture; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BaseFormComponent.h"
struct TESTexture {
    BaseFormComponent _base;
    BSFixedString_char_83b572b4 textureName;
};
static_assert(sizeof(TESTexture) == 16, "TESTexture layout differs from the PDB");
