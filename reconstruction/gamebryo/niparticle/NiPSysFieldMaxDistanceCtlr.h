// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// NiPSysFieldMaxDistanceCtlr, GetTargetValue, SetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { struct NiPSysFieldModifierFields; }

class NiPSysFieldMaxDistanceCtlr
{
public:
    void GetTargetValue(float& value) const;
    void SetTargetValue(float value);

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysFieldModifierFields* modifier;
};
