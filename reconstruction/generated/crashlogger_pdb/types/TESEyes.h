// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEyes; size 0x48
#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
struct TESEyes {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESTexture _base_TESTexture;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad41;
    unsigned short pad42;
    unsigned int pad44;
};
static_assert(sizeof(TESEyes) == 72, "TESEyes layout differs from the PDB");
