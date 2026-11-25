// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortalSharedNode, CreateClone, BSPortal, lights and portal: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, CreateClone: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// 0xfe9c20 BSPortalSharedNode::CreateClone
// CI hash: 0xfe9c20 ?CreateClone@BSPortalSharedNode@@UEAAPEAVNiObject@@AEAVNiCloningProcess@@@Z
#include "BSPortalSharedNode_fe9c20.h"

inline BSPortalSharedNode::BSPortalSharedNode(BSPortal* owner)
    : NiNode(0)
{
    flags |= 1u << 11;
    portal = owner;
}

NiObject* BSPortalSharedNode::CreateClone(NiCloningProcess&)
{
    return new BSPortalSharedNode(portal);
}
