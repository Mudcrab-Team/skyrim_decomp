// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSColorForm; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "Color.h"
#include "Flag_d5bcd2af.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
struct BGSColorForm_ed89af9a {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    Color color;
    Flag_d5bcd2af flags;
};
static_assert(sizeof(BGSColorForm_ed89af9a) == 56, "BGSColorForm_ed89af9a layout differs from the PDB");
