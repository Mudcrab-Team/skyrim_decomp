// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiMatrix3; size 0x24
#pragma once
struct NiMatrix3 {
    float entry[3][3];
};
static_assert(sizeof(NiMatrix3) == 36, "NiMatrix3 layout differs from the PDB");
