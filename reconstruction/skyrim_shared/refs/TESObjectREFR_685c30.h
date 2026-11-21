// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout of the reference and cell calls.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// TESObjectREFR, TESObjectCELL, GetSubmergeLevel, GetHeight, GetWaterHeight, GetExteriorWaterHeight, parentCell: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>

class TESObjectCELL
{
public:
    float GetExteriorWaterHeight() const;
};

class TESObjectREFR
{
public:
    float GetSubmergeLevel(float height, TESObjectCELL* cell) const;

private:
    float GetWaterHeight() const;
    float GetHeight() const;

    std::uint8_t unknown00[0x60];
    TESObjectCELL* parentCell;
};
