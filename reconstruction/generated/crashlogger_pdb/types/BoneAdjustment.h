// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoneAdjustment; size 0x38
#pragma once

struct NiAVObject;
struct BoneAdjustment {
    unsigned char rotation_raw[40];
    NiAVObject* bone;
    float zOffset;
    unsigned char undefined_34[4];
};
static_assert(sizeof(BoneAdjustment) == 56, "BoneAdjustment layout differs from the PDB");
