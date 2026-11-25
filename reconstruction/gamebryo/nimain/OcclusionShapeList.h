// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: Original list traversal and storage reconstruction from the pinned image.
// BSPortalGraph and BSOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// ShapeItem, OcclusionShapeList, Next and Find: GUESS(low) STANDIN
#pragma once

#include "PortalHeapObject.h"
void operator delete(void* object, std::size_t size) noexcept;
class BSOcclusionShape;
struct ShapeItem : PortalHeapObject {
    ShapeItem() noexcept : next(nullptr), prev(nullptr), element(nullptr) {}
    ShapeItem* next;
    ShapeItem* prev;
    BSOcclusionShape* element;
};
struct OcclusionShapeList {
    ShapeItem* head;
    ShapeItem* tail;
    unsigned int size;
    static BSOcclusionShape*& Next(ShapeItem*& position)
    {
        auto& value = position->element;
        position = position->next;
        return value;
    }
    ShapeItem* Find(BSOcclusionShape* shape) const
    {
        ShapeItem* position = head;
        while (position) {
            auto* item = position;
            if (shape == Next(position)) {
                return item;
            }
        }
        return nullptr;
    }
};
