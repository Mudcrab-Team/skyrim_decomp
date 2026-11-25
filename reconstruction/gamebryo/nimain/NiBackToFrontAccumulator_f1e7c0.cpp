// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Adapted bodies: NiRefObject::~NiRefObject follows the project reconstruction in gamebryo/nimain/NiAccumulator.h.
// 0xf1e7c0 NiBackToFrontAccumulator::~NiBackToFrontAccumulator
#include "NiBackToFrontAccumulator_f1e7c0.h"

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
