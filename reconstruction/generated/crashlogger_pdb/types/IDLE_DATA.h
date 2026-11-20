// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IDLE_DATA; size 0x6
#pragma once
struct IDLE_DATA {
    unsigned char loopMin;
    unsigned char loopMax;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char animationGroupSelection;
    unsigned short replayDelay;
};
static_assert(sizeof(IDLE_DATA) == 6, "IDLE_DATA layout differs from the PDB");
