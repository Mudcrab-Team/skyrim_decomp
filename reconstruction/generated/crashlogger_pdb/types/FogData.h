// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FogData; size 0x20
#pragma once
struct FogData {
    float dayNear;
    float dayFar;
    float nightNear;
    float nightFar;
    float dayPower;
    float nightPower;
    float dayMax;
    float nightMax;
};
static_assert(sizeof(FogData) == 32, "FogData layout differs from the PDB");
