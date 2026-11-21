// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TypeInfo; size 0x8
#pragma once

#include "RawType.h"
struct TypeInfo {
    RawType _rawType;
    unsigned char _pad_0[4];
};
static_assert(sizeof(TypeInfo) == 8, "TypeInfo layout differs from the PDB");
