// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// SlotEntry1dc120, CopyEntryTable1dc120, Slot0, Slot1, Slot2, CopyFrom, kEntryCount: GUESS(low)
#pragma once

#include <cstddef>

class SlotEntry1dc120
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void CopyFrom(SlotEntry1dc120* a_source);
};

constexpr std::size_t kEntryCount = 38;

void CopyEntryTable1dc120(SlotEntry1dc120** a_dest, SlotEntry1dc120** a_source);  // compared: 0x1dc120
