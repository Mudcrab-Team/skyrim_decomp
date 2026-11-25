// Source exposure: mixed (local binary analysis and public names).
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0x4e0f40 (skyrim_shared/pathfinding/PathingDoor): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// PathingDoorVirtualTarget: GUESS(low) STANDIN
// Function121b410, Owner121b410: GUESS(low) STANDIN
// Slot2, Function4e0ee0, member, padding: GUESS(low) STANDIN
#pragma once
#include "PathingDoor.h"

class Owner121b410
{
public:
    virtual std::uint32_t Slot2() const;
    void Function4e0ee0(PathingDoorVirtualTarget* target);
    void Function121b410(PathingDoorVirtualTarget* target);
    std::uint8_t padding[0x10];
    std::uint32_t member;
};

