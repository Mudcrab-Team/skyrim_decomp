// Source exposure: mixed (community names/prototypes; pinned-image observations).
// Code origin: original; minimal declarations for observed accesses
// SPDX-License-Identifier: CC0-1.0
// TESHavokUtilities, GetDamageForImpact: CRASHLOGGER_PDB(59818@2026.10.24)
// GetDamageForImpact prototype: SYMBOLS(fo4-pdb)
// ImpactSetting, ImpactMinimumMass, ImpactMediumMass, ImpactLowDamage, ImpactHighMass, ImpactMediumDamage, ImpactHighDamage, ImpactMinimumSpeed, ImpactSpeedScale, ImpactSpeedOffset: STANDIN OBSERVED
#pragma once
#include <cstdint>
struct ImpactSetting {
    std::uint8_t reserved[8];
    float value;
};
extern ImpactSetting ImpactMinimumMass;
extern ImpactSetting ImpactMediumMass;
extern ImpactSetting ImpactLowDamage;
extern ImpactSetting ImpactHighMass;
extern ImpactSetting ImpactMediumDamage;
extern ImpactSetting ImpactHighDamage;
extern ImpactSetting ImpactMinimumSpeed;
extern ImpactSetting ImpactSpeedScale;
extern ImpactSetting ImpactSpeedOffset;
class TESHavokUtilities {
public:
    static float GetDamageForImpact(float mass, float speed);
};
