// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalSharedNode, NiNode, BSPortal, lights, portal, BSTArrayHeapAllocator, BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// FrustumArray and Clear: GUESS(low)
// CI hash: 0xfea050 ??_GBSPortalSharedNode@@UEAAPEAXI@Z
// 0xfea050 BSPortalSharedNode::dtor_deleting
#include "BSPortalSharedNode_fea050.h"

BSPortalSharedNode::BSPortalSharedNode(BSPortal* owner) : NiNode(0)
{
    flags |= 1u << 11;
    portal = owner;
}

BSPortalSharedNode::~BSPortalSharedNode()
{
    lights.Clear();
    portal = nullptr;
}
