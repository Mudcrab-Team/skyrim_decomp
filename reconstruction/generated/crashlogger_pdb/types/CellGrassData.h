// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellGrassData; size 0x48
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_float_ed3b09d0_c6f3c315.h"
#include "BSTArray_unsigned_int_4b643186.h"
#include "NiPointer_RE__BSMultiStreamInstanceTriShape_59b3bbf8.h"
struct CellGrassData {
    unsigned long long grassTypeKey;
    BSFixedString_char_83b572b4 grassModelKey;
    NiPointer_RE__BSMultiStreamInstanceTriShape_59b3bbf8 triShape;
    BSTArray_unsigned_int_4b643186 instanceGroupIndicies;
    BSTArray_float_ed3b09d0_c6f3c315 instanceGroupFadeAlphas;
};
static_assert(sizeof(CellGrassData) == 72, "CellGrassData layout differs from the PDB");
