// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DynamicAttenuationCharacteristics; size 0x18
#pragma once

#include "BSIAttenuationCharacteristics.h"
#include "DataType.h"
struct DynamicAttenuationCharacteristics {
    BSIAttenuationCharacteristics _base;
    DataType data;
};
static_assert(sizeof(DynamicAttenuationCharacteristics) == 24, "DynamicAttenuationCharacteristics layout differs from the PDB");
