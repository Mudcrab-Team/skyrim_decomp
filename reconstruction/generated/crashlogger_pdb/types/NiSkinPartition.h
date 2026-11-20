// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinPartition; size 0x28
#pragma once

#include "NiObject_de5bc370.h"
#include "SimpleArray_RE__NiSkinPartition__Partition_3805ec28.h"
struct NiSkinPartition {
    NiObject_de5bc370 _base;
    unsigned int numPartitions;
    unsigned int pad14;
    SimpleArray_RE__NiSkinPartition__Partition_3805ec28 partitions;
    unsigned int vertexCount;
    unsigned int unk24;
};
static_assert(sizeof(NiSkinPartition) == 40, "NiSkinPartition layout differs from the PDB");
