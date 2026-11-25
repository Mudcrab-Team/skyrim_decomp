// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x25b250 TESRegionPointList::SegmentIntersects
// Adapted bodies: TESRegionPointList::SegmentIntersects follows fo4-private@1b765c70 src/Shared/Regions/TESRegionPointList.cpp:576
#include "TESRegionPointList_25b250.h"

bool TESRegionPointList::SegmentIntersects(const TESRegionPoint* a, const TESRegionPoint* b) const
{
    if (!a || !b || iCount < 3)
        return false;
    const TESRegionPointList* node = this;
    do
    {
        const TESRegionPointList* next = node->m_pkNext;
        if (!next)
            next = this;
        if (TESRegionPoint::LineSegmentsIntersect(a, b, node->m_item, next->m_item))
            return true;
        node = next;
    } while (node != this);
    return false;
}
