// Source exposure: mixed (labelled declarations; pinned image observations).
// Code origin: original; handwritten from observed behavior
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xfa7ed0 NiPSysBoundUpdateModifier::IsEqual
#include "NiPSysBoundUpdateModifier_fa7ed0.h"

// Requires equal inherited state and the same bounds-update interval.
bool NiPSysBoundUpdateModifier::IsEqual(NiObject* other)
{
    if (!NiPSysModifier::IsEqual(other))
        return false;
    if (reinterpret_cast<NiPSysBoundUpdateModifier*>(other)->m_sUpdateSkip != m_sUpdateSkip)
        return false;
    return true;
}
