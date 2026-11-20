// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GuardInfo; size 0xc
#pragma once
struct GuardInfo {
    unsigned int guard;
    unsigned int unk4;
    unsigned int unk8;
};
static_assert(sizeof(GuardInfo) == 12, "GuardInfo layout differs from the PDB");
