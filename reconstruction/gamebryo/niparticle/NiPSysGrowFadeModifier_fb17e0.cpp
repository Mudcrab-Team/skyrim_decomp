// Source exposure: mixed (labelled declarations; pinned image observations).
// Code origin: original; handwritten from observed behavior
// SPDX-License-Identifier: CC0-1.0
// 0xfb17e0 NiPSysGrowFadeModifier::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiPSysGrowFadeModifier_fb17e0.h"

bool NiPSysGrowFadeModifier::IsEqual(NiObject* other)
{
    if (!NiPSysModifier::IsEqual(other))
        return false;
    auto modifier = reinterpret_cast<NiPSysGrowFadeModifier*>(other);
    return m_fGrowTime == modifier->m_fGrowTime &&
           m_usGrowGeneration == modifier->m_usGrowGeneration &&
           m_fFadeTime == modifier->m_fFadeTime &&
           m_fBaseScale == modifier->m_fBaseScale &&
           m_usFadeGeneration == modifier->m_usFadeGeneration;
}
