// Source exposure: mixed (community declarations; pinned-image observations; sibling symbol facts).
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0xfc1080 NiPSysFieldModifier::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiPSysFieldModifier_fc1080.h"

bool NiPSysFieldModifier::IsEqual(NiObject* object)
{
    if (!NiPSysModifier::IsEqual(object))
        return false;
    auto* other = static_cast<NiPSysFieldModifier*>(object);
    if (m_pkFieldObj) {
        if (!other->m_pkFieldObj || !m_pkFieldObj->IsEqual(other->m_pkFieldObj))
            return false;
    } else if (other->m_pkFieldObj) {
        return false;
    }
    if (other->m_fMagnitude != m_fMagnitude)
        return false;
    if (other->m_fAttenuation != m_fAttenuation) {
        return false;
    } else {
        if (other->m_bUseMaxDistance != m_bUseMaxDistance)
            return false;
        if (other->m_fMaxDistance != m_fMaxDistance)
            return false;
        return true;
    }
}
