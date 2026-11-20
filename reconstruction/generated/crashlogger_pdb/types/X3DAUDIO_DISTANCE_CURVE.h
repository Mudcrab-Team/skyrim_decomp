// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: X3DAUDIO_DISTANCE_CURVE; size 0xc
#pragma once

struct X3DAUDIO_DISTANCE_CURVE_POINT;
#pragma pack(push, 4)
struct X3DAUDIO_DISTANCE_CURVE {
    X3DAUDIO_DISTANCE_CURVE_POINT* pPoints;
    unsigned int PointCount;
};
#pragma pack(pop)
static_assert(sizeof(X3DAUDIO_DISTANCE_CURVE) == 12, "X3DAUDIO_DISTANCE_CURVE layout differs from the PDB");
