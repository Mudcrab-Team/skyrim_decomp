// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout for the fall-damage calculation.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// TESObjectREFR, TESObjectCELL, GetSubmergeLevel: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CalculateFallDamage: GUESS(low)
// positionZ, parentCell: OBSERVED
#pragma once

#include <cstdint>

class TESObjectCELL;

class TESObjectREFR
{
public:
    float CalculateFallDamage(float distance, float thresholdScale);

private:
    float GetSubmergeLevel(float height, TESObjectCELL* cell) const;

    std::uint8_t unknown00[0x5c];
    float positionZ;
    TESObjectCELL* parentCell;
};
