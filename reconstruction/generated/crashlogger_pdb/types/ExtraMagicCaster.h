// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraMagicCaster; size 0x58
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "MagicCaster.h"
struct ExtraMagicCaster {
    BSExtraData_4ca6af76 _base;
    MagicCaster _base_MagicCaster;
};
static_assert(sizeof(ExtraMagicCaster) == 88, "ExtraMagicCaster layout differs from the PDB");
