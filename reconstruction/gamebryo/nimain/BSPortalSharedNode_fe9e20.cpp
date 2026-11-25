// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalSharedNode, OnVisible, BSPortalGraphEntry, FindVisibility, BSCompoundFrustum, Prethread, BSCullingProcess, portalGraphEntry, compoundFrustum and cullMode: CRASHLOGGER_PDB(59818@2026.10.24)
// Cull, child array interface: GUESS(low)
// 0xfe9e20 BSPortalSharedNode::OnVisible
// CI hash: 0xfe9e20 ?OnVisible@BSPortalSharedNode@@QEAAXAEAVNiCullingProcess@@H@Z
#include "BSPortalSharedNode_fe9e20.h"

void BSPortalSharedNode::OnVisible(NiCullingProcess& baseProcess, int)
{
    auto& process = static_cast<BSCullingProcess&>(baseProcess);
    if (childCount > 0) {
        auto* previous = process.compoundFrustum;
        auto* visibility = process.portalGraphEntry ? process.portalGraphEntry->FindVisibility(this) : nullptr;
        if (visibility || process.cullMode == BSCPCullingType::kAllPass ||
            process.cullMode == BSCPCullingType::kIgnoreMultiBounds) {
            process.compoundFrustum = visibility;
            if (visibility) {
                visibility->Prethread();
            }
            const unsigned short end = freeIndex;
            for (unsigned short i = 0; i < end; ++i) {
                if (auto* child = children[i]) {
                    child->Cull(process, -1);
                }
            }
            process.compoundFrustum = previous;
        }
    }
}
