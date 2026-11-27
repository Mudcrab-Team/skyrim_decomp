// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xcfb5d0 BSInputEventQueue::EnqueueDeviceConnectEvent
#include "BSInputEventQueue_cfb5d0.h"

// Appends a device connect event from the fixed-size pool to the event queue.
void BSInputEventQueue::EnqueueDeviceConnectEvent(std::uint32_t a_device, bool a_connected)
{
    if (deviceConnectEventCount >= 1)
    {
        return;
    }

    DeviceConnectEvent& ev = deviceConnectEvents[deviceConnectEventCount];
    ev.device = a_device;
    ev.connected = a_connected;
    InputEvent* queued = &deviceConnectEvents[deviceConnectEventCount];
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
    ++deviceConnectEventCount;
}
