// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1e6480, SetFlagBit11, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9, MarkChanged, unk08, flags: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Unit1e6480
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void MarkChanged(std::uint32_t a_flag);

    void SetFlagBit11(bool a_set);  // compared: 0x1e6480

    std::uint64_t unk08;  // 08
    std::uint32_t flags;  // 10
};
static_assert(offsetof(Unit1e6480, flags) == 0x10, "Unit1e6480::flags offset");
