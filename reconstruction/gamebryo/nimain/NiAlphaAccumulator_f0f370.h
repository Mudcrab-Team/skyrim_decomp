// NiAlphaAccumulator, NiBackToFrontAccumulator, List, Node, NiCamera, BSGeometry: GUESS(low)
// camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, head, tail, size: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
// _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body; public prefix adapted from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Adapted powerof3 declarations are licensed under GPL-3.0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// NiAlphaAccumulator, NiBackToFrontAccumulator, List, Node, NiCamera, BSGeometry: GUESS(low)
// camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, head, tail, size: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
// _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class NiCamera; class BSGeometry; struct Node;
struct List { Node* head; Node* tail; std::uint32_t size; };
class NiBackToFrontAccumulator {
public:
    NiBackToFrontAccumulator();
    virtual ~NiBackToFrontAccumulator();
    volatile std::uint32_t _refCount;
    std::uint32_t _pad0C;
    const NiCamera* camera;
    List itemsList;
    std::int32_t numItems, maxItems;
    BSGeometry** items;
    float* depths;
    std::int32_t currItem;
};
class NiAlphaAccumulator : public NiBackToFrontAccumulator {
public:
    NiAlphaAccumulator();
    ~NiAlphaAccumulator() override;
    bool observeNoSortHint, sortByClosestPoint, interfaceSort;
};
