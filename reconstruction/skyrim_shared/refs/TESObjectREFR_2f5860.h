// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout for the reference's water-height query.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// TESObjectREFR, TESObjectCELL, GetWaterHeight, GetExteriorWaterHeight, LOADED_REF_DATA, relevantWaterHeight, loadedData, parentCell: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>

class TESObjectCELL
{
public:
    float GetExteriorWaterHeight() const;
};

struct LOADED_REF_DATA
{
    std::uint8_t unknown00[0x20];
    float relevantWaterHeight;
};

class TESObjectREFR
{
public:
    float GetWaterHeight() const;

private:
    std::uint8_t unknown00[0x60];
    TESObjectCELL* parentCell;
    const LOADED_REF_DATA* loadedData;
};
