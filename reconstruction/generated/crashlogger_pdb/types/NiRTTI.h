// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiRTTI; size 0x10
#pragma once
struct NiRTTI {
    unsigned char* name;
    NiRTTI* baseRTTI;
};
static_assert(sizeof(NiRTTI) == 16, "NiRTTI layout differs from the PDB");
