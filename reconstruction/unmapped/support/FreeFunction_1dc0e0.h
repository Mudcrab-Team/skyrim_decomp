// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// SlotEntry1dc0e0, ClearEntryTable1dc0e0, Slot0, Slot1, Clear, kEntryCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class SlotEntry1dc0e0
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Clear();
};

constexpr std::size_t kEntryCount = 38;

void ClearEntryTable1dc0e0(SlotEntry1dc0e0** a_entries);  // compared: 0x1dc0e0
