// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoundingVolumeData; size 0x38
#pragma once

struct hkAabbUint32_693359bb;
struct BoundingVolumeData {
    unsigned int min[3];
    unsigned char expansionMin[3];
    unsigned char expansionShift;
    unsigned int max[3];
    unsigned char expansionMax[3];
    unsigned char pad1F;
    unsigned short numChildShapeAabbs;
    unsigned short capacityChildShapeAabbs;
    unsigned int pad24;
    hkAabbUint32_693359bb* childShapeAabbs;
    unsigned int* childShapeKeys;
};
static_assert(sizeof(BoundingVolumeData) == 56, "BoundingVolumeData layout differs from the PDB");
