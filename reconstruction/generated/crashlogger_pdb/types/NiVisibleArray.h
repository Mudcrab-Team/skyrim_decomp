// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiVisibleArray; size 0x18
#pragma once

struct BSGeometry;
struct NiVisibleArray {
    BSGeometry** array;
    unsigned int currentSize;
    unsigned int allocatedSize;
    unsigned int growBy;
    unsigned char undefined_14[4];
};
static_assert(sizeof(NiVisibleArray) == 24, "NiVisibleArray layout differs from the PDB");
