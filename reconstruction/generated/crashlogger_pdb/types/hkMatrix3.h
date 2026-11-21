// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMatrix3; size 0x30
#pragma once

#include "hkVector4.h"
struct hkMatrix3 {
    hkVector4 col0;
    hkVector4 col1;
    hkVector4 col2;
};
static_assert(sizeof(hkMatrix3) == 48, "hkMatrix3 layout differs from the PDB");
