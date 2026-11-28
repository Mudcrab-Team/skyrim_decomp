// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ActionState186e30, ActionBase186e30, ActionObj186e30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ActionState186e30
{
    ActionState186e30() : unk00(-1), unk04(0), unk08(0) {}

    std::int32_t unk00;   // 00
    std::uint8_t unk04;   // 04
    std::uint32_t unk08;  // 08
};

class ActionBase186e30
{
public:
    ActionBase186e30() : next(0) {}
    virtual ~ActionBase186e30() {}

    void* next;  // 08
};

class ActionObj186e30 : public ActionBase186e30
{
public:
    ActionObj186e30();  // compared: 0x186e30

    void* unk10;             // 10
    std::uint8_t unk18;      // 18
    std::uint32_t unk1C;     // 1C
    std::uint64_t unk20;     // 20
    ActionState186e30 state; // 28
    void* unk38;             // 38
};
