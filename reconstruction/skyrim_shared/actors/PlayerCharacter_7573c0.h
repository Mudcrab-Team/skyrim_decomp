// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// PlayerCharacter::UpdateLowHealthIMod: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// g_lowHealthIModEnabled, g_lowHealthThreshold, g_lowHealthActive, g_lowHealthIntensity, g_lowHealthIntensityDefault: GUESS(low)
#pragma once

extern bool g_lowHealthIModEnabled;
extern float g_lowHealthThreshold;
extern bool g_lowHealthActive;
extern float g_lowHealthIntensity;
extern const float g_lowHealthIntensityDefault;

class PlayerCharacter
{
public:
    void UpdateLowHealthIMod(float healthFraction);
};
