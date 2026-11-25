// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfe9d10 BSPortalSharedNode::BSPortalSharedNode
#include "BSPortalSharedNode_fe9d10.h"

BSPortalSharedNode::BSPortalSharedNode(BSPortal* owner)
    : NiNode(0), lights()
{
    flags |= 1u << 11;
    portal = owner;
}
