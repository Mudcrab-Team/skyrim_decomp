// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxDisplayContext; size 0x300
#pragma once
#pragma pack(push, 4)
struct GFxDisplayContext {
    void* cxform;
    void* matrix;
    void* world3D;
    void* perspective3D;
    void* view3D;
    unsigned char has3DWorld;
    unsigned char undefined_29[7];
    unsigned char flag30;
    unsigned char undefined_31[47];
    void* sharedRef;
    void* renderConfig;
    unsigned char undefined_70[24];
    void* gradientParams;
    void* imageCreator;
    void* fontCacheManager;
    void* log;
    void* meshCacheManager;
    void* unkB0;
    void* unkB8;
    unsigned int unkC0;
    void* baseMatrix;
    unsigned char undefined_cc[20];
    void* unkE0;
    unsigned int maskDrawDepth;
    unsigned int maskStackSize;
    unsigned int clipDepth;
    unsigned char undefined_f4[4];
    void* clipObjects[64];
    unsigned char undefined_2f8[8];
};
#pragma pack(pop)
static_assert(sizeof(GFxDisplayContext) == 768, "GFxDisplayContext layout differs from the PDB");
