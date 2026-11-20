// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSColorForm; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Color_aa361e09.h"
#include "Flag_a4a94b8a.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSColorForm {
    TESForm _base;
    TESFullName _base_TESFullName;
    Color_aa361e09 color;
    Flag_a4a94b8a flags;
};
static_assert(sizeof(BGSColorForm) == 56, "BGSColorForm layout differs from the PDB");
