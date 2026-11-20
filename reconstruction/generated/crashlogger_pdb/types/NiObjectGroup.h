// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiObjectGroup; size 0x20
#pragma once
struct NiObjectGroup {
    unsigned int size;
    unsigned int pad04;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned int unk18;
    unsigned int pad1C;
};
static_assert(sizeof(NiObjectGroup) == 32, "NiObjectGroup layout differs from the PDB");
