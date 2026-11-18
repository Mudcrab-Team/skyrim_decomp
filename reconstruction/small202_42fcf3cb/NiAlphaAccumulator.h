// Origin: adapted declarations from powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0, NiAccumulator.h, NiBackToFrontAccumulator.h, NiAlphaAccumulator.h, NiTListBase.h; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Adapted declarations are licensed under GPL-3.0.
// NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, head, tail, size: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// GeometryList: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ListNode, Functionf0f210, CopyMembers: GUESS(low)
#pragma once
#include "netimmerse/NiObject.h"
#include <cstdint>
class NiCamera;
class BSGeometry;
struct ListNode;
struct GeometryList {
 ListNode* head;
 ListNode* tail;
 std::uint32_t size;
};
class NiAccumulator : public NiObject {
public:
 const NiCamera* camera;
};
class NiBackToFrontAccumulator : public NiAccumulator {
public:
 void CopyMembers(NiBackToFrontAccumulator*);
 GeometryList itemsList;
 std::int32_t numItems;
 std::int32_t maxItems;
 BSGeometry** items;
 float* depths;
 std::int32_t currItem;
};
class NiAlphaAccumulator : public NiBackToFrontAccumulator {
public:
 void Functionf0f210(NiAlphaAccumulator*);
 bool observeNoSortHint;
 bool sortByClosestPoint;
 bool interfaceSort;
};
