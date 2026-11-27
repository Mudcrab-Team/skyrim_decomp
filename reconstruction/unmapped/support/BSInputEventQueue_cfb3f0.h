// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// BSInputEventQueue, BSInputEventQueue::EnqueueCharEvent, InputEvent: CRASHLOGGER_PDB(59818@2026.10.24)
// CharEvent, vtable, device, unk0C, next, keyCode, unk1C, unk00, charEventCount, unk0C2, charEvents, unk2A8, queueHead, queueTail: GUESS
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

struct CharEvent : public InputEvent
{
    std::uint32_t keyCode;
    std::uint32_t unk1C;
};

class BSInputEventQueue
{
public:
    void EnqueueCharEvent(std::uint32_t a_keyCode);

    std::uint8_t unk00[0x8];
    std::uint32_t charEventCount;
    std::uint8_t unk0C2[0x1FC];
    CharEvent charEvents[5];
    std::uint8_t unk2A8[0x2B0];
    InputEvent* queueHead;
    InputEvent* queueTail;
};

static_assert(sizeof(CharEvent) == 0x20, "CharEvent size");
static_assert(offsetof(BSInputEventQueue, charEventCount) == 0x08, "charEventCount offset");
static_assert(offsetof(BSInputEventQueue, charEvents) == 0x208, "charEvents offset");
static_assert(offsetof(BSInputEventQueue, queueHead) == 0x558, "queueHead offset");
static_assert(offsetof(BSInputEventQueue, queueTail) == 0x560, "queueTail offset");
