// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OBJ_TREE; size 0x30
#pragma once
struct OBJ_TREE {
    float trunkFlexibility;
    float branchFlexibility;
    float trunkAmplitude;
    float frontAmplitude;
    float backAmplitude;
    float sideAmplitude;
    float frontFrequency;
    float backFrequency;
    float sideFrequency;
    float leafFlexibility;
    float leafAmplitude;
    float leafFrequency;
};
static_assert(sizeof(OBJ_TREE) == 48, "OBJ_TREE layout differs from the PDB");
