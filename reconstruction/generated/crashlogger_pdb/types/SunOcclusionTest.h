// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SunOcclusionTest; size 0x18
#pragma once
struct SunOcclusionTest {
    void* occlusionQuery;
    float percentOccluded;
    unsigned int pixelCount;
    unsigned int frameCount;
    bool waiting;
    unsigned char undefined_15[3];
};
static_assert(sizeof(SunOcclusionTest) == 24, "SunOcclusionTest layout differs from the PDB");
