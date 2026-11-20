// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointFunctionDataText; size 0x10
#pragma once

#include "BGSEntryPointFunctionData.h"
#include "BSFixedString_char_83b572b4.h"
struct BGSEntryPointFunctionDataText {
    BGSEntryPointFunctionData _base;
    BSFixedString_char_83b572b4 text;
};
static_assert(sizeof(BGSEntryPointFunctionDataText) == 16, "BGSEntryPointFunctionDataText layout differs from the PDB");
