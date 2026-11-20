// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxTranslator; size 0x20
#pragma once

#include "GFxState_6a94ada2.h"
#include "WordWrappingType.h"
struct GFxTranslator {
    GFxState_6a94ada2 _base;
    WordWrappingType wwMode;
    unsigned int pad1C;
};
static_assert(sizeof(GFxTranslator) == 32, "GFxTranslator layout differs from the PDB");
