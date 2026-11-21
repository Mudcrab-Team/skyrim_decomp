// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModel; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BaseFormComponent.h"
struct ID;
struct TESModel_c52655e4 {
    BaseFormComponent _base;
    BSFixedString_char_83b572b4 model;
    ID* textures;
    unsigned int* addons;
    unsigned short numTextures;
    unsigned short numAddons;
    unsigned int pad24;
};
static_assert(sizeof(TESModel_c52655e4) == 40, "TESModel_c52655e4 layout differs from the PDB");
