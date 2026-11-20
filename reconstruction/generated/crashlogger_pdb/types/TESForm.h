// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESForm; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
#include "TESFileContainer.h"
struct TESForm {
    BaseFormComponent _base;
    TESFileContainer sourceFiles;
    unsigned int formFlags;
    unsigned int formID;
    unsigned short inGameFormFlags;  // InGameFormFlag in the PDB is wider than this slot
    unsigned char formType;  // FormType in the PDB is wider than this slot
    unsigned char pad1B;
    unsigned int pad1C;
};
static_assert(sizeof(TESForm) == 32, "TESForm layout differs from the PDB");
