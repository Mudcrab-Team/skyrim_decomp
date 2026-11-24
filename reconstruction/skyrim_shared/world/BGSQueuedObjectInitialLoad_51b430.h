// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSQueuedObjectInitialLoad, BGSQueuedObjectInitialLoad::Function51b430, QueuedTarget, unk0C, state, target: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct QueuedTarget
{
    std::uint8_t unk00[0xC];
    std::uint32_t state;  // unk0C
};

class BGSQueuedObjectInitialLoad
{
public:
    std::uint8_t unk00[0x18];
    QueuedTarget* target;

    bool Function51b430() const;  // compared: 0x51b430
};
