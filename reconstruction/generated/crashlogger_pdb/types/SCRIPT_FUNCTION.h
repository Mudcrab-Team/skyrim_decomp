// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SCRIPT_FUNCTION; size 0x50
#pragma once

#include "SCRIPT_OUTPUT.h"
struct SCRIPT_PARAMETER;
struct SCRIPT_FUNCTION {
    unsigned char* functionName;
    unsigned char* shortName;
    SCRIPT_OUTPUT output;
    unsigned int pad14;
    unsigned char* helpString;
    bool referenceFunction;
    unsigned char pad21;
    unsigned short numParams;
    unsigned int pad24;
    SCRIPT_PARAMETER* params;
    unsigned char executeFunction_raw[8];
    unsigned char compileFunction_raw[8];
    unsigned char conditionFunction_raw[8];
    bool editorFilter;
    bool invalidatesCellList;
    unsigned short pad4A;
    unsigned int pad4C;
};
static_assert(sizeof(SCRIPT_FUNCTION) == 80, "SCRIPT_FUNCTION layout differs from the PDB");
