// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CullDescriptor; size 0x68
#pragma once

struct BSGeometryListCullingProcess;
struct NiAVObject_968dc716;
struct NiCamera;
struct CullDescriptor {
    char32_t* accumulator;
    char32_t* unk08;
    NiCamera* camera;
    char32_t* unk18;
    char32_t* unk20;
    char32_t* unk28;
    BSGeometryListCullingProcess* geometryListProcess;
    char32_t* unk38;
    NiAVObject_968dc716* sceneRoot;
    char32_t* lightData;
    char32_t* unk50;
    int renderTargetIndex;
    unsigned char ringSelect;
    unsigned char undefined_5d[3];
    unsigned char unk60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char undefined_63[5];
};
static_assert(sizeof(CullDescriptor) == 104, "CullDescriptor layout differs from the PDB");
