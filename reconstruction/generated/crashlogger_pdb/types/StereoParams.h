// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StereoParams; size 0x14
#pragma once
struct StereoParams {
    float displayWidthCm;
    float distortion;
    float displayDiagInches;
    float displayAspectRatio;
    float eyeSeparationCm;
};
static_assert(sizeof(StereoParams) == 20, "StereoParams layout differs from the PDB");
