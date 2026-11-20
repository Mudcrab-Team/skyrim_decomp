// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Unk28; size 0x28
#pragma once
struct Unk28 {
    int unk0;
    int unk4;
    unsigned char unk8[8];
    void* unk10;
    void* unk18;
    unsigned char unk20;
    unsigned char undefined_21[7];
};
static_assert(sizeof(Unk28) == 40, "Unk28 layout differs from the PDB");
