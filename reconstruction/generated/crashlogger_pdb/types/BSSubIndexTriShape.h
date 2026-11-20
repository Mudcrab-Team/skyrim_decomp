// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSubIndexTriShape; size 0x178
#pragma once

#include "BSTriShape.h"
struct SegmentData;
struct BSSubIndexTriShape {
    BSTriShape _base;
    SegmentData* segmentData;
    unsigned int numSegments;
    unsigned int unkSegCount;
    bool unk170;
    bool nonSegmented;
    unsigned char undefined_172[6];
};
static_assert(sizeof(BSSubIndexTriShape) == 376, "BSSubIndexTriShape layout differs from the PDB");
