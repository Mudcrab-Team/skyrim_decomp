// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinData::BoneVertData; size 0xc
#pragma once
#pragma pack(push, 4)
struct NiSkinData__BoneVertData {
    unsigned short Vert_0;
    char _pad_2[2];
    float* Weight_4;
};
#pragma pack(pop)
static_assert(sizeof(NiSkinData__BoneVertData) == 12, "NiSkinData__BoneVertData layout differs from the PDB");
