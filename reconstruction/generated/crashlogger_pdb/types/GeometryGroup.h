// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GeometryGroup; size 0x28
#pragma once

#include "PersistentPassList.h"
struct BSBatchRenderer;
struct GeometryGroup {
    BSBatchRenderer* batchRenderer;
    PersistentPassList passList;
    unsigned long long UnkPtr4;
    float depth;
    unsigned short count;
    unsigned char flags;
    unsigned char undefined_27[1];
};
static_assert(sizeof(GeometryGroup) == 40, "GeometryGroup layout differs from the PDB");
