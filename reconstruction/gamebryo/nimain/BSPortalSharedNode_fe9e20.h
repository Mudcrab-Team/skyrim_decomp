// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortalSharedNode, OnVisible, BSPortalGraphEntry, FindVisibility, BSCompoundFrustum, Prethread, BSCullingProcess, portalGraphEntry, compoundFrustum and cullMode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCullingProcess, OnVisible: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Cull, child array interface: GUESS(low)
#pragma once

#include "../../generated/crashlogger_pdb/types/BSCPCullingType.h"
#include "BSPortalSharedNode_fe9c20.h"
#include "BSCompoundFrustum_ff72a0.h"

class NiCullingProcess {};
struct BSPortalGraphEntry {
    BSCompoundFrustum* FindVisibility(NiNode* node) const;
};
struct BSCullingProcess : NiCullingProcess {
    unsigned char unknown00[0x30190];
    BSPortalGraphEntry* portalGraphEntry;
    BSCPCullingType cullMode;
    BSCompoundFrustum* compoundFrustum;
};
static_assert(sizeof(struct BSPortalSharedNode) == 0x148, "BSPortalSharedNode layout");
