// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FilterInfo690be0, Controller690be0, Process690be0, Actor690be0, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, GetCollisionFilterInfo, GetController, value, v, outFilter, unk00, process: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FilterInfo690be0
{
    std::uint32_t value;  // 0x00

    explicit FilterInfo690be0(std::uint32_t v) : value(v) {}
};

struct Controller690be0
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void GetCollisionFilterInfo(std::uint32_t& outFilter);
};

struct Process690be0
{
    Controller690be0* GetController();
};

class Actor690be0
{
public:
    FilterInfo690be0 GetCollisionFilterInfo();

    std::uint8_t unk00[0xF8];  // 0x00
    Process690be0* process;    // 0xF8
};
static_assert(offsetof(Actor690be0, process) == 0xF8, "Actor690be0 process offset");
