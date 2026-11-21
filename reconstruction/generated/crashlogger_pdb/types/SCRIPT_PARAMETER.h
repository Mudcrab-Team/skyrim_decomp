// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SCRIPT_PARAMETER; size 0x10
#pragma once

#include "SCRIPT_PARAM_TYPE.h"
struct SCRIPT_PARAMETER {
    unsigned char* paramName;
    SCRIPT_PARAM_TYPE paramType;
    bool optional;
    unsigned char pad0D;
    unsigned short pad0E;
};
static_assert(sizeof(SCRIPT_PARAMETER) == 16, "SCRIPT_PARAMETER layout differs from the PDB");
