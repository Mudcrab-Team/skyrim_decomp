// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xcfb3f0 BSInputEventQueue::EnqueueCharEvent
#include "BSInputEventQueue_cfb3f0.h"

// Appends a character input event from the fixed-size pool to the event queue.
void BSInputEventQueue::EnqueueCharEvent(std::uint32_t a_keyCode)
{
    if (charEventCount >= 5)
    {
        return;
    }

    CharEvent& ev = charEvents[charEventCount];
    ev.keyCode = a_keyCode;
    ev.device = 0;
    InputEvent* queued = &charEvents[charEventCount];
    if (!queueHead)
    {
        queueHead = queued;
    }
    if (queueTail)
    {
        queueTail->next = queued;
    }
    queueTail = queued;
    queued->next = nullptr;
    ++charEventCount;
}
