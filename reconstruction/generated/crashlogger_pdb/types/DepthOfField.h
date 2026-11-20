// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DepthOfField; size 0x10
#pragma once
struct DepthOfField {
    float strength;
    float distance;
    float range;
    unsigned short flags;
    unsigned short skyBlurRadius;  // SkyBlurRadius in the PDB is wider than this slot
};
static_assert(sizeof(DepthOfField) == 16, "DepthOfField layout differs from the PDB");
