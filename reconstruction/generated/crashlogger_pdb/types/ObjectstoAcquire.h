// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectstoAcquire; size 0x28
#pragma once
struct ObjectstoAcquire {
    unsigned long long unk00;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned long long unk20;
};
static_assert(sizeof(ObjectstoAcquire) == 40, "ObjectstoAcquire layout differs from the PDB");
