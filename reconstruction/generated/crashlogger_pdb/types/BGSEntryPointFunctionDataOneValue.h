// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointFunctionDataOneValue; size 0x10
#pragma once

#include "BGSEntryPointFunctionData.h"
struct BGSEntryPointFunctionDataOneValue {
    BGSEntryPointFunctionData _base;
    float data;
    unsigned int pad0C;
};
static_assert(sizeof(BGSEntryPointFunctionDataOneValue) == 16, "BGSEntryPointFunctionDataOneValue layout differs from the PDB");
