// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFullName; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BaseFormComponent.h"
struct TESFullName {
    BaseFormComponent _base;
    BSFixedString_char_83b572b4 fullName;
};
static_assert(sizeof(TESFullName) == 16, "TESFullName layout differs from the PDB");
