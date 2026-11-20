// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CreateGrassParams; size 0x50
#pragma once

struct GrassParam;
struct NiPoint3;
struct TESObjectLAND_8ae461ea;
struct CreateGrassParams {
    int CellX;
    int CellY;
    int quad;
    unsigned char pad0C[4];
    TESObjectLAND_8ae461ea* land;
    NiPoint3* grassPatchStart;
    GrassParam* grassParam;
    float* grassDensityPcts;
    float densityMultiplier;
    float distanceFromWaterLevel;
    unsigned int underwaterState;
    float waterHeight;
    unsigned int minSlopeDegrees;
    unsigned int maxSlopeDegrees;
    unsigned char pad48[8];
};
static_assert(sizeof(CreateGrassParams) == 80, "CreateGrassParams layout differs from the PDB");
