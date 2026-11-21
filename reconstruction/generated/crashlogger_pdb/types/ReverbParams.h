// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReverbParams; size 0xe
#pragma once
struct ReverbParams {
    unsigned short decayTime;
    unsigned short hfReference;
    unsigned char roomFilter;
    unsigned char roomHFFilter;
    unsigned char reflections;
    unsigned char reverb;
    unsigned char decayHFRatio;
    unsigned char reflectionDelay;
    unsigned char reverbDelay;
    unsigned char diffusionPct;
    unsigned char densityPct;
    unsigned char pad0D;
};
static_assert(sizeof(ReverbParams) == 14, "ReverbParams layout differs from the PDB");
