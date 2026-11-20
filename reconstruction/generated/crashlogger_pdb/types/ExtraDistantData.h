// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDistantData; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPoint3.h"
struct ExtraDistantData {
    BSExtraData_4ca6af76 _base;
    NiPoint3 landNormal;
    unsigned int pad1C;
};
static_assert(sizeof(ExtraDistantData) == 32, "ExtraDistantData layout differs from the PDB");
