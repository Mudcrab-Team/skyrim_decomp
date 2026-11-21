// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CodeInfo; size 0x10
#pragma once

#include "hkVector4.h"
struct CodeInfo {
    hkVector4 offset;
};
static_assert(sizeof(CodeInfo) == 16, "CodeInfo layout differs from the PDB");
