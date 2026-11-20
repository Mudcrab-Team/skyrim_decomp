// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLoadScreen; size 0x38
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
struct LoadNIFData;
struct TESLoadScreen {
    TESForm _base;
    TESCondition_4d3cdc88 conditions;
    LoadNIFData* loadNIFData;
    BSFixedString_char_83b572b4 loadingText;
};
static_assert(sizeof(TESLoadScreen) == 56, "TESLoadScreen layout differs from the PDB");
