// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from
// CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the powerof3 fork (GPL-3.0) uses the same ones.
// 0x2709b0 TESGrass::GetUnderwaterState
// 0x270a30 TESGrass::SetUnderwaterState
// 0x270900 TESGrass::GetDensity
// 0x270910 TESGrass::GetDistanceFromWaterLevel
// 0x270960 TESGrass::GetMaxSlopeDegrees
// 0x270990 TESGrass::GetMinSlopeDegrees
// 0x270890 TESGrass::~TESGrass
#include "TESGrass.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the deleting destructor, as the original unit did. Its body is a minimal stand-in.
TESGrass::TESGrass()
{
}

TESGrass::~TESGrass()
{
}

std::uint8_t TESGrass::GetDensity() const
{
    return data.density;
}

std::uint8_t TESGrass::GetMinSlopeDegrees() const
{
    return data.minSlopeDegrees;
}

std::uint8_t TESGrass::GetMaxSlopeDegrees() const
{
    return data.maxSlopeDegrees;
}

std::uint16_t TESGrass::GetDistanceFromWaterLevel() const
{
    return data.distanceFromWaterLevel;
}

// SetDistanceFromWaterLevel, GetHeightRange, GetColorRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESGrass::SetDistanceFromWaterLevel(std::uint16_t a_unitsFromWater)
{
    data.distanceFromWaterLevel = a_unitsFromWater;
}

float TESGrass::GetHeightRange() const
{
    return data.heightRange;
}

float TESGrass::GetColorRange() const
{
    return data.colorRange;
}

TESGrass::GRASS_WATER_STATE TESGrass::GetUnderwaterState() const
{
    return data.underwater;
}

void TESGrass::SetUnderwaterState(GRASS_WATER_STATE a_waterState)
{
    data.underwater = a_waterState;
}
