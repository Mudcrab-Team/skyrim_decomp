// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalGraph and RemoveOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd9fa0 BSPortalGraph::RemoveOcclusionShape
// CI hash: 0xfd9fa0 ?RemoveOcclusionShape@BSPortalGraph@@QEAAXPEAVBSOcclusionShape@@@Z
#include "BSPortalGraph_fd9fa0.h"

static void DisposeItem(OcclusionShapeList& list, ShapeItem* item)
{
    item->element = nullptr;
    delete item;
    --list.size;
}

void BSPortalGraph::RemoveOcclusionShape(BSOcclusionShape* shape)
{
    if (!shape) {
        return;
    }
    auto* item = occlusionShapes.Find(shape);
    if (item) {
        if (item == occlusionShapes.head) {
            item = occlusionShapes.head;
            occlusionShapes.head = item->next;
            if (occlusionShapes.head) {
                occlusionShapes.head->prev = nullptr;
            } else {
                occlusionShapes.tail = nullptr;
            }
            DisposeItem(occlusionShapes, item);
        } else if (item == occlusionShapes.tail) {
            item = occlusionShapes.tail;
            occlusionShapes.tail = item->prev;
            if (occlusionShapes.tail) {
                occlusionShapes.tail->next = nullptr;
            } else {
                occlusionShapes.head = nullptr;
            }
            DisposeItem(occlusionShapes, item);
        } else {
            auto* next = item->next;
            auto* previous = item->prev;
            if (previous) {
                previous->next = next;
            }
            if (next) {
                next->prev = previous;
            }
            DisposeItem(occlusionShapes, item);
        }
    }
}
