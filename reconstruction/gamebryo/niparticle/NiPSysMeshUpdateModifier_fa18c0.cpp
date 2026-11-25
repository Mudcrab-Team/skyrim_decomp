// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa18c0 NiPSysMeshUpdateModifier::RegisterStreamables
// Adapted bodies: none
#include "NiPSysMeshUpdateModifier_fa18c0.h"
bool NiPSysMeshUpdateModifier::RegisterStreamables(NiStream& stream)
{
    if (!NiPSysModifier::RegisterStreamables(stream)) {
        return false;
    }
    for (std::uint32_t i = 0; i < m_kMeshes.size; ++i) {
        NiObject* mesh = m_kMeshes.data[i];
        if (mesh) {
            mesh->RegisterStreamables(stream);
        }
    }
    return true;
}
