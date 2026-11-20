// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// NiPSysInitialRotSpeedVarCtlr, GetTargetValue, SetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { struct NiPSysRotationModifierFields; }

class NiPSysInitialRotSpeedVarCtlr
{
public:
    void GetTargetValue(float& value) const;
    void SetTargetValue(float value);

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysRotationModifierFields* modifier;
};
