// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceData; size 0xa0
#pragma once

#include "ImageSpaceBaseData.h"
#include "ImageSpaceModData.h"
struct ImageSpaceData {
    ImageSpaceBaseData baseData;
    ImageSpaceModData modData;
    float baseAmount;
    float modAmount;
};
static_assert(sizeof(ImageSpaceData) == 160, "ImageSpaceData layout differs from the PDB");
