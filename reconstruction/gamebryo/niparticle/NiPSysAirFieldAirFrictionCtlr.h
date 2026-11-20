// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// NiPSysAirFieldAirFrictionCtlr, GetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { struct NiPSysAirFieldModifierFields; }

class NiPSysAirFieldAirFrictionCtlr
{
public:
    void GetTargetValue(float& value) const;

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysAirFieldModifierFields* modifier;
};
