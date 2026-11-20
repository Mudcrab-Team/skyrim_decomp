// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// NiPSysEmitterDeclinationCtlr, GetTargetValue, SetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { struct NiPSysEmitterFields; }

class NiPSysEmitterDeclinationCtlr
{
public:
    void GetTargetValue(float& value) const;
    void SetTargetValue(float value);

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysEmitterFields* modifier;
};
