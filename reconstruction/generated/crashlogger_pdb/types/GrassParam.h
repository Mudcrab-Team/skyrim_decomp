// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GrassParam; size 0x50
#pragma once
struct GrassParam {
    unsigned char* modelName;
    unsigned int grassFormID;
    float positionRange;
    float heightRange;
    float colorRange;
    unsigned int waveOffsetRange;
    float wavePeriod;
    bool hasVertexLighting;
    bool hasUniformScaling;
    bool fitsToSlope;
    unsigned char pad23;
    unsigned int pad24;
    unsigned char denstityPctPerQuadVertex_raw[40];
};
static_assert(sizeof(GrassParam) == 80, "GrassParam layout differs from the PDB");
