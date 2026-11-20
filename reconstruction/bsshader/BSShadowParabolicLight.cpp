// Source exposure: mixed (community headers; the pinned image listing).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from the pinned community headers.
// Adapted bodies: none
// 0x1588da0 ShadowRefLeaf::~ShadowRefLeaf
// 0x1588e20 BSShadowParabolicLight::GetIsOmniLight
// 0x1588d50 BSShadowParabolicLight::ReturnShadowmaps
#include <intrin.h>

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

NiRefObjectInline::NiRefObjectInline()
{
}

NiRefObjectInline::~NiRefObjectInline()
{
    // the object count is shared across threads, so the decrement must be atomic
    _InterlockedDecrement(&niRefObjectTotalCount);
}

ShadowRefLeaf::~ShadowRefLeaf()
{
}
