// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TypeData; size 0x40
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "MaxSpeeds.h"
struct TypeData {
    BSFixedString_char_83b572b4 typeName;
    MaxSpeeds defaultData;
    float directional;
    float movementSpeed;
    float rotationSpeed;
};
static_assert(sizeof(TypeData) == 64, "TypeData layout differs from the PDB");
