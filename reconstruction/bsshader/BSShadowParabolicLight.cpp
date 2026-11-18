// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x1588e20 BSShadowParabolicLight::GetIsOmniLight
// 0x1588d50 BSShadowParabolicLight::ReturnShadowmaps
#include "BSShadowParabolicLight.h"

// GetIsParabolicLight, GetNeedsClipPlanes, GetPassExtraParam: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool BSShadowParabolicLight::GetIsParabolicLight()
{
    return true;
}

bool BSShadowParabolicLight::GetNeedsClipPlanes()
{
    return true;
}

std::uint32_t BSShadowParabolicLight::GetPassExtraParam()
{
    return 0;
}

// TODO body: RVA 0x1588e20, 11 bytes, BSShadowParabolicLight::GetIsOmniLight.
bool BSShadowParabolicLight::GetIsOmniLight()
{
    return state140 == 2;
}

// TODO body: RVA 0x1588d50, 31 bytes, BSShadowParabolicLight::ReturnShadowmaps.
void BSShadowParabolicLight::ReturnShadowmaps()
{
    if (state140 == 2) {
        shadowmap148->state144 = 0xffffffff;
    }
    return ReturnShadowmapsTarget();
}
