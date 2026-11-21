// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: X3DAUDIO_CONE; size 0x20
#pragma once
struct X3DAUDIO_CONE {
    float InnerAngle;
    float OuterAngle;
    float InnerVolume;
    float OuterVolume;
    float InnerLPF;
    float OuterLPF;
    float InnerReverb;
    float OuterReverb;
};
static_assert(sizeof(X3DAUDIO_CONE) == 32, "X3DAUDIO_CONE layout differs from the PDB");
