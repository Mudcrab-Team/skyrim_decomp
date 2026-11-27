// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa2080 NiPSysMeshUpdateModifier::ProcessClone
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "NiPSysMeshUpdateModifier_fa2080.h"

// Process populated mesh entries after the modifier base.
void NiPSysMeshUpdateModifier::ProcessClone(NiCloningProcess& cloning)
{
    NiPSysModifier::ProcessClone(cloning);
    for (std::uint32_t i = 0; i < m_kMeshes.freeIndex; ++i) {
        NiObject* mesh = m_kMeshes.data[i];
        if (mesh) {
            mesh->ProcessClone(cloning);
        }
    }
}
