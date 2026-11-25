// Near miss: 14.5 alignment distance | control-flow
// Source exposure: mixed
// Code origin: handwritten from local target observations; community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysMeshUpdateModifier, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfa19c0 NiPSysMeshUpdateModifier::IsEqual
#include "include/fa19c0/NiPSysMeshUpdateModifier_fa19c0.h"

// Compare the modifier state and each possibly empty mesh entry.
bool NiPSysMeshUpdateModifier::IsEqual(NiObject* object)
{
    if (!NiPSysModifier::IsEqual(object))
    {
        return false;
    }
    NiPSysMeshUpdateModifier* other;
    other = static_cast<NiPSysMeshUpdateModifier*>(object);
    if (m_kMeshes._freeIdx != other->m_kMeshes._freeIdx)
    {
        return false;
    }
    { std::uint32_t i = 0; for (; i < m_kMeshes._freeIdx;)
    {
        NiObject* mesh = m_kMeshes.GetAt(i);
        NiObject* otherMesh = other->m_kMeshes.GetAt(i);
        if (0 != mesh)
        {
            if (!otherMesh || !mesh->IsEqual(otherMesh))
            {
                return false;
            }
        }
        else if (otherMesh)
        {
            return false;
        } i++;
    } }
    return true;
}
