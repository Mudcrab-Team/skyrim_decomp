// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StripPointData; size 0xb8
#pragma once

#include "NiColorA_7eee66f4.h"
#include "NiPoint3.h"
struct StripPointData {
    NiPoint3 ptCenter;
    unsigned char verts_raw[48];
    unsigned char lastverts_raw[48];
    NiPoint3 directionVector;
    unsigned char tangentSideVectors_raw[24];
    unsigned long long unk90;
    unsigned int unk98;
    NiColorA_7eee66f4 pointColor;
    float pointSize;
    float pointRadius;
    float ptCreationTime;
};
static_assert(sizeof(StripPointData) == 184, "StripPointData layout differs from the PDB");
