// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// SoundMessageList, SoundMessageList::AddHead: CRASHLOGGER_PDB(59818@2026.10.24)
// SoundMessage, unk00, next, prev, head, tail: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

struct SoundMessage
{
    std::uint8_t unk00[0x30];
    SoundMessage* next;
    SoundMessage* prev;
};

class SoundMessageList
{
public:
    void AddHead(SoundMessage* a_msg);

    SoundMessage* head;
    SoundMessage* tail;
};

static_assert(offsetof(SoundMessage, next) == 0x30, "next offset");
static_assert(offsetof(SoundMessage, prev) == 0x38, "prev offset");
