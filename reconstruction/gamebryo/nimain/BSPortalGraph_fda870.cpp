// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalGraph, RemoveAlwaysRenderChild, alwaysRenderChildren, NiAVObject and flags: CRASHLOGGER_PDB(59818@2026.10.24)
// ObjectReference and ObjectArray: GUESS(low)
// Cookbook: 0xfda870 29
// 0xfda870 BSPortalGraph::RemoveAlwaysRenderChild
// CI hash: 0xfda870 ?RemoveAlwaysRenderChild@BSPortalGraph@@QEAAXPEAVNiAVObject@@@Z
#include "BSPortalGraph_fda870.h"

void BSPortalGraph::RemoveAlwaysRenderChild(NiAVObject* child)
{
    for (unsigned int i = 0; i < alwaysRenderChildren.size; ++i) {
        ObjectReference current(alwaysRenderChildren.data[i]);
        if (current.object && current.object == child) {
            alwaysRenderChildren.Erase(i, 1);
            current.object->flags &= ~1u;
            break;
        }
    }
}
