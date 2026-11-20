// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoopData; size 0xc
#pragma once
struct LoopData {
    float loopBegin;
    float loopEnd;
    unsigned int loopCount;
};
static_assert(sizeof(LoopData) == 12, "LoopData layout differs from the PDB");
