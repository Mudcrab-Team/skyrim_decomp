// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSDismemberSkinInstance; size 0xa0
#pragma once

#include "NiSkinInstance.h"
struct Data_44aaa72b;
struct BSDismemberSkinInstance {
    NiSkinInstance _base;
    int numPartitions;
    unsigned int pad8C;
    Data_44aaa72b* partitions;
    bool unk98;
    unsigned char pad99;
    unsigned short pad9A;
    unsigned int pad9C;
};
static_assert(sizeof(BSDismemberSkinInstance) == 160, "BSDismemberSkinInstance layout differs from the PDB");
