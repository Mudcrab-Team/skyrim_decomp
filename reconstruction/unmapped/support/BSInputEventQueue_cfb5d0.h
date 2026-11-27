// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// BSInputEventQueue, BSInputEventQueue::EnqueueDeviceConnectEvent, InputEvent: CRASHLOGGER_PDB(59818@2026.10.24)
// DeviceConnectEvent, vtable, device, unk0C, next, connected, unk19, unk00, deviceConnectEventCount, unk18, deviceConnectEvents, unk358, queueHead, queueTail: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

struct InputEvent
{
    void* vtable;
    std::uint32_t device;
    std::uint32_t unk0C;
    InputEvent* next;
};

struct DeviceConnectEvent : public InputEvent
{
    bool connected;
    std::uint8_t unk19[7];
};

class BSInputEventQueue
{
public:
    void EnqueueDeviceConnectEvent(std::uint32_t a_device, bool a_connected);

    std::uint8_t unk00[0x14];
    std::uint32_t deviceConnectEventCount;
    std::uint8_t unk18[0x320];
    DeviceConnectEvent deviceConnectEvents[1];
    std::uint8_t unk358[0x200];
    InputEvent* queueHead;
    InputEvent* queueTail;
};

static_assert(sizeof(DeviceConnectEvent) == 0x20, "DeviceConnectEvent size");
static_assert(offsetof(BSInputEventQueue, deviceConnectEventCount) == 0x14, "deviceConnectEventCount offset");
static_assert(offsetof(BSInputEventQueue, deviceConnectEvents) == 0x338, "deviceConnectEvents offset");
static_assert(offsetof(BSInputEventQueue, queueHead) == 0x558, "queueHead offset");
static_assert(offsetof(BSInputEventQueue, queueTail) == 0x560, "queueTail offset");
