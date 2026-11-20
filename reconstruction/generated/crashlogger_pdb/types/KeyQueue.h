// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KeyQueue; size 0x64c
#pragma once
struct KeyQueue {
    unsigned char buffer_raw[1600];
    unsigned int putIdx;
    unsigned int getIdx;
    unsigned int count;
};
static_assert(sizeof(KeyQueue) == 1612, "KeyQueue layout differs from the PDB");
