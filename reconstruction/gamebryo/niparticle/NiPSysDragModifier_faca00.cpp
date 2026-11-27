// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysDragModifier, NiPSysDragModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_pkDragObj, m_kDragAxis, m_fPercentage, m_fRange, m_fFalloff: SYMBOLS(fo4-pdb)
// unknown10: GUESS(low)
// 0xfaca00 NiPSysDragModifier::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// Cookbook: 0xfaca00 48
#include "NiPSysDragModifier_faca00.h"

bool NiPSysDragModifier::IsEqual(NiObject* object)
{
    if (NiPSysModifier::IsEqual(object)) {
        NiPSysDragModifier* other;
        other = static_cast<NiPSysDragModifier*>(object);
        if (m_pkDragObj) {
            if (!other->m_pkDragObj || !m_pkDragObj->IsEqual(other->m_pkDragObj)) {
                return false;
            }
        } else if (other->m_pkDragObj) {
            return false;
        }
        return other->m_kDragAxis[0] == m_kDragAxis[0] &&
               other->m_kDragAxis[1] == m_kDragAxis[1] &&
               other->m_kDragAxis[2] == m_kDragAxis[2] &&
               other->m_fPercentage == m_fPercentage &&
               other->m_fRange == m_fRange &&
               other->m_fFalloff == m_fFalloff;
    } else {
        return false;
    }
}
