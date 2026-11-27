// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: destructor and list helpers from the project unit NiBackToFrontAccumulator_f1e7c0.
// NiBackToFrontAccumulator, itemsList, items, depths: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseBuffer, RemoveHead: GUESS(low)
// 0xf1ec30 NiBackToFrontAccumulator::~NiBackToFrontAccumulator
// CI hash: 0xf1ec30 ??_GNiBackToFrontAccumulator@@UEAAPEAXI@Z
#include "NiBackToFrontAccumulator_f1ec30.h"

void ReleaseBuffer(void* buffer);

inline NiRefObject::~NiRefObject()
{
    // The object count is shared across threads.
    _InterlockedDecrement(&ms_totalObjects);
}

inline NiObject::~NiObject() = default;
inline NiAccumulator::~NiAccumulator() = default;

inline void GeometryList::RemoveHead()
{
    Node* old = head;
    head = old->next;
    if (head) {
        head->previous = nullptr;
    } else {
        tail = nullptr;
    }
    old->item = nullptr;
    delete old;
    --count;
}

inline GeometryList::~GeometryList()
{
    Node* node = head;
    while (node) {
        Node* old = node;
        node = node->next;
        old->item = nullptr;
        delete old;
    }
    count = 0;
    head = nullptr;
    tail = nullptr;
}

NiBackToFrontAccumulator::~NiBackToFrontAccumulator()
{
    ReleaseBuffer(items);
    ReleaseBuffer(depths);
    while (itemsList.count) {
        itemsList.RemoveHead();
    }
}
