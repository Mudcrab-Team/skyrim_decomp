// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DOF; size 0x10
#pragma once
struct DOF {
    unsigned int strength;
    unsigned int distance;
    unsigned int range;
    bool useTarget;
    unsigned char flags;  // DepthOfFieldMode in the PDB is wider than this slot
    unsigned short pad0E;
};
static_assert(sizeof(DOF) == 16, "DOF layout differs from the PDB");
