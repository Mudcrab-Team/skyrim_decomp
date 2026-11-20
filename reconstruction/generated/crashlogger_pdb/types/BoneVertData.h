// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoneVertData; size 0x8
#pragma once
struct BoneVertData {
    unsigned short vert;
    unsigned short pad2;
    float weight;
};
static_assert(sizeof(BoneVertData) == 8, "BoneVertData layout differs from the PDB");
