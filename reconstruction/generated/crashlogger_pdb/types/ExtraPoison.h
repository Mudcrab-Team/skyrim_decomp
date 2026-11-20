// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPoison; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
struct AlchemyItem_e992fb73;
struct ExtraPoison {
    BSExtraData_4ca6af76 _base;
    AlchemyItem_e992fb73* poison;
    unsigned int count;
    unsigned int pad1C;
};
static_assert(sizeof(ExtraPoison) == 32, "ExtraPoison layout differs from the PDB");
