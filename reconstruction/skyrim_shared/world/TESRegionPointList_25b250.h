// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionPointList.cpp:576
// TESRegionPointList, TESRegionPointList::SegmentIntersects, TESRegionPointList::iCount, TESRegionPoint, TESRegionPoint::LineSegmentsIntersect: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// m_item, m_pkNext: GUESS(low); the list node members, named as the sibling body uses them
// unk10: GUESS(low)
#pragma once

#include <cstdint>

struct TESRegionPoint
{
    static bool LineSegmentsIntersect(const TESRegionPoint* a, const TESRegionPoint* b, const TESRegionPoint* c, const TESRegionPoint* d);
};

class TESRegionPointList
{
public:
    bool SegmentIntersects(const TESRegionPoint* a, const TESRegionPoint* b) const;

    TESRegionPoint*     m_item;    // 00
    TESRegionPointList* m_pkNext;  // 08
    std::uint8_t        unk10[0x20];
    std::uint32_t       iCount;    // 30
};
static_assert(sizeof(TESRegionPointList) == 0x38, "TESRegionPointList size");
