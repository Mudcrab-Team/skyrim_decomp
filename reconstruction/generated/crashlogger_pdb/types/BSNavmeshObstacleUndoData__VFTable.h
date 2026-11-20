// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshObstacleUndoData__VFTable; size 0x10
#pragma once

struct NiRefObject;
struct BSNavmeshObstacleUndoData__VFTable {
    unsigned long long*(*dtor_0)(NiRefObject* , char);
    int (*Delete_8)(int (*)(unsigned long long, unsigned long long));
};
static_assert(sizeof(BSNavmeshObstacleUndoData__VFTable) == 16, "BSNavmeshObstacleUndoData__VFTable layout differs from the PDB");
