// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// NiPSysAirFieldSpreadCtlr, GetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { struct NiPSysAirFieldModifierFields; }

class NiPSysAirFieldSpreadCtlr
{
public:
    void GetTargetValue(float& value) const;

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysAirFieldModifierFields* modifier;
};
