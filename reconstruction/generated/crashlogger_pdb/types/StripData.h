// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StripData; size 0x28
#pragma once

struct StripPointData;
struct StripData {
    StripPointData* ptRingBuffer;
    unsigned int pointCount;
    unsigned int segmentCount;
    int ptCapacity;
    int headIndex;
    int tailIndex;
    float lastUpdateTime;
    double lastPtUpdate;
};
static_assert(sizeof(StripData) == 40, "StripData layout differs from the PDB");
