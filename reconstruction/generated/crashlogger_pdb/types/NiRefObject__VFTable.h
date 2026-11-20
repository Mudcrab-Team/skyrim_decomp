// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiRefObject__VFTable; size 0x10
#pragma once

struct NiRefObject;
struct NiRefObject__VFTable {
    unsigned long long*(*dtor_0)(NiRefObject* , char);
    int (*Delete_8)(int (*)(unsigned long long, unsigned long long));
};
static_assert(sizeof(NiRefObject__VFTable) == 16, "NiRefObject__VFTable layout differs from the PDB");
