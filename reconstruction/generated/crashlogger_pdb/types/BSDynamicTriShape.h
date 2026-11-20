// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSDynamicTriShape; size 0x180
#pragma once

#include "BSSpinLock.h"
#include "BSTriShape.h"
struct BSDynamicTriShape {
    BSTriShape _base;
    void* dynamicData;
    BSSpinLock lock;
    unsigned int dataSize;
    unsigned int frameCount;
    unsigned int unk178;
    unsigned int unk17C;
};
static_assert(sizeof(BSDynamicTriShape) == 384, "BSDynamicTriShape layout differs from the PDB");
