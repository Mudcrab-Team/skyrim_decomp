// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LineMeshContainer; size 0x78
#pragma once

#include "LineMeshArrayHdr.h"
struct GHashSetTable;
struct LineMeshContainer {
    GHashSetTable* table;
    LineMeshArrayHdr arrayA;
    LineMeshArrayHdr arrayB;
    void* ref;
    unsigned char undefined_40[8];
    float unk48;
    float unk4C;
    unsigned char undefined_50[4];
    float unk54;
    float unk58;
    unsigned char undefined_5c[20];
    unsigned char flag70;
    unsigned char flag71;
    unsigned char undefined_72[6];
};
static_assert(sizeof(LineMeshContainer) == 120, "LineMeshContainer layout differs from the PDB");
