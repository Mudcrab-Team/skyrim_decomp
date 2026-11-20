// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DisabledEntryPoint; size 0x4
#pragma once
struct DisabledEntryPoint {
    unsigned short unk0;
    unsigned short disabledPoints;  // DisabledPoint in the PDB is wider than this slot
};
static_assert(sizeof(DisabledEntryPoint) == 4, "DisabledEntryPoint layout differs from the PDB");
