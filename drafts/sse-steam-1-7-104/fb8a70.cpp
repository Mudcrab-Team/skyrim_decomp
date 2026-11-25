// Near miss: 7.0 alignment distance | register-schedule
// Exposure detail: (community declarations; local target observations).
// Source exposure: mixed
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none.
// 0xfb8a70 NiPSysRotationModifier::IsEqual

#include "include/fb8a70/NiPSysRotationModifier_fb8a70.h"
bool NiPSysRotationModifier::IsEqual(NiObject* object)
{
    auto* other = reinterpret_cast<NiPSysRotationModifier*>(object);
    if (!NiPSysModifier::IsEqual(object))
        return false;
    if (m_fInitialRotSpeed != other->m_fInitialRotSpeed ||
        m_fInitialRotSpeedVar != other->m_fInitialRotSpeedVar ||
        other->m_bRandomRotSpeedSign != m_bRandomRotSpeedSign ||
        m_fInitialRotAngle != other->m_fInitialRotAngle ||
        m_fInitialRotAngleVar != other->m_fInitialRotAngleVar ||
        other->m_bRandomInitialAxis != m_bRandomInitialAxis ||
        m_kInitialAxis[0] != other->m_kInitialAxis[0] ||
        m_kInitialAxis[1] != other->m_kInitialAxis[1] ||
        m_kInitialAxis[2] != other->m_kInitialAxis[2]) {
        return false; }
    return true;
}
