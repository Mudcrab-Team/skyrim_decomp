// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LIGHT_CREATE_PARAMS; size 0x30
#pragma once

struct BSLensFlareRenderData;
struct NiAVObject;
struct LIGHT_CREATE_PARAMS {
    bool dynamic;
    bool shadowLight;
    bool portalStrict;
    bool affectLand;
    bool affectWater;
    bool neverFades;
    unsigned char undefined_6[2];
    float fov;
    float falloff;
    float nearDistance;
    float depthBias;
    unsigned int sceneGraphIndex;
    unsigned char undefined_1c[4];
    NiAVObject* restrictedNode;
    BSLensFlareRenderData* lensFlareData;
};
static_assert(sizeof(LIGHT_CREATE_PARAMS) == 48, "LIGHT_CREATE_PARAMS layout differs from the PDB");
