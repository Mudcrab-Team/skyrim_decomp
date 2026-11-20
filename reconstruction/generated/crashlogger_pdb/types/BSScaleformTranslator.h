// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSScaleformTranslator; size 0x50
#pragma once

#include "BSTranslator.h"
#include "GFxTranslator.h"
struct BSScaleformTranslator {
    GFxTranslator _base;
    BSTranslator translator;
};
static_assert(sizeof(BSScaleformTranslator) == 80, "BSScaleformTranslator layout differs from the PDB");
