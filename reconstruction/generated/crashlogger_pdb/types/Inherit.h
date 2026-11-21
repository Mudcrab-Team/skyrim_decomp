// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Inherit
#pragma once
enum class Inherit : int {
    kAmbientColor = 1,
    kDirectionalColor = 2,
    kFogColor = 4,
    kFogNear = 8,
    kFogFar = 16,
    kDirectionalRotation = 32,
    kDirectionalFade = 64,
    kClipDistance = 128,
    kFogPower = 256,
    kFogMax = 512,
    kLightFadeDistances = 1024,
};
