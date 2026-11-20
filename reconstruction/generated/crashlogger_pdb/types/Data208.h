// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Data208; size 0x38
#pragma once
struct Data208 {
    unsigned long long unk00;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
    unsigned long long unk28;
    Data208* next;
};
static_assert(sizeof(Data208) == 56, "Data208 layout differs from the PDB");
