// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SAOEffectParams; size 0x70
#pragma once

struct ImageSpaceEffect;
struct SAOEffectParams {
    ImageSpaceEffect* blurH;
    ImageSpaceEffect* blurV;
    ImageSpaceEffect* cameraZ;
    ImageSpaceEffect* compositeSAO;
    ImageSpaceEffect* compositeFog;
    ImageSpaceEffect* compositeSAOFog;
    ImageSpaceEffect* minify;
    ImageSpaceEffect* minifyContrast;
    ImageSpaceEffect* rawAO;
    ImageSpaceEffect* rawAONoTemporal;
    bool enableSAO;
    unsigned char pad51[3];
    unsigned int unk54;
    unsigned long long unk58;
    unsigned long long unk60;
    unsigned long long unk68;
};
static_assert(sizeof(SAOEffectParams) == 112, "SAOEffectParams layout differs from the PDB");
