// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinPartition_DrawContext; size 0x28
#pragma once

struct BSGeometry;
struct NiBoneMatrixSetterI;
struct NiSkinPartition_DrawContext {
    NiBoneMatrixSetterI* setter;
    BSGeometry* geometry;
    unsigned long long unk10;
    unsigned int singleLevel;
    unsigned int lodIndex;
    float unk20;
    int dynamicBufferOffset;
};
static_assert(sizeof(NiSkinPartition_DrawContext) == 40, "NiSkinPartition_DrawContext layout differs from the PDB");
