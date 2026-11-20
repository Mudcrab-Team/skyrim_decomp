// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WorkBenchData; size 0x2
#pragma once
struct WorkBenchData {
    unsigned char benchType;  // BenchType in the PDB is wider than this slot
    unsigned char usesSkill;  // ActorValue in the PDB is wider than this slot
};
static_assert(sizeof(WorkBenchData) == 2, "WorkBenchData layout differs from the PDB");
