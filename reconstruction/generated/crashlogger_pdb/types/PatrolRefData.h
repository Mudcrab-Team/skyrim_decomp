// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PatrolRefData; size 0x28
#pragma once
struct PatrolRefData {
    unsigned long long unk00;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
};
static_assert(sizeof(PatrolRefData) == 40, "PatrolRefData layout differs from the PDB");
