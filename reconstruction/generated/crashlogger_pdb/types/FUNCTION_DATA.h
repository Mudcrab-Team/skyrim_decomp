// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FUNCTION_DATA; size 0x18
#pragma once
struct FUNCTION_DATA {
    unsigned short function;  // FunctionID in the PDB is wider than this slot
    unsigned short pad02;
    unsigned int pad04;
    void* params[2];
};
static_assert(sizeof(FUNCTION_DATA) == 24, "FUNCTION_DATA layout differs from the PDB");
