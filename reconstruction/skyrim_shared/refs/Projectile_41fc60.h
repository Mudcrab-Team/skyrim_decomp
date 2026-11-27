// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Projectile, GetDeathForce: CRASHLOGGER_PDB(59818@2026.10.24)
// gAltInMin, gAltInMax, gAltOutMin, gAltOutMax, gInMin, gInMax, gOutMin, gOutMax: GUESS(low)
#pragma once

extern float gAltInMin;
extern float gAltInMax;
extern float gAltOutMin;
extern float gAltOutMax;
extern float gInMin;
extern float gInMax;
extern float gOutMin;
extern float gOutMax;

class Projectile
{
public:
    static float GetDeathForce(float value, bool useAlternate);
};
