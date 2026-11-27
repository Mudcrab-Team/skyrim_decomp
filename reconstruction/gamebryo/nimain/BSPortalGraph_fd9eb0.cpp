// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalGraph, BSOcclusionShape, AddOcclusionShape, RemoveOcclusionShape and occlusionShapes: CRASHLOGGER_PDB(59818@2026.10.24)
// ShapeItem, ShapeList and Find: GUESS(low)
// 0xfd9eb0 BSPortalGraph::AddOcclusionShape
// CI hash: 0xfd9eb0 ?AddOcclusionShape@BSPortalGraph@@QEAAXPEAVBSOcclusionShape@@@Z
#include "BSPortalGraph_fd9eb0.h"

void BSPortalGraph::AddOcclusionShape(BSOcclusionShape* shape)
{
    if (shape && !occlusionShapes.Find(shape)) {
        auto* item = new ShapeItem;
        item->element = shape;
        item->next = nullptr;
        item->prev = occlusionShapes.tail;
        if (occlusionShapes.tail) {
            occlusionShapes.tail->next = item;
        } else {
            occlusionShapes.head = item;
        }
        ++occlusionShapes.size;
        occlusionShapes.tail = item;
    }
}
