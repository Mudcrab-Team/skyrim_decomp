// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TES_LIGHT_FLAGS
// one of 2 different PDB types sharing this name
#pragma once
enum class TES_LIGHT_FLAGS_d6c37478 : int {
    kNone = 0,
    kDynamic = 1,
    kCanCarry = 2,
    kNegative = 4,
    kFlicker = 8,
    kDeepCopy = 16,
    kOffByDefault = 32,
    kFlickerSlow = 64,
    kPulse = 128,
    kPulseSlow = 256,
    kSpotlight = 512,
    kSpotShadow = 1024,
    kHemiShadow = 2048,
    kOmniShadow = 4096,
    kPortalStrict = 8192,
};
