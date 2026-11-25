// Source exposure: mixed (local binary analysis and public names).
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0x4e0f40 (skyrim_shared/pathfinding/PathingDoor): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// PathingDoorVirtualTarget: GUESS(low) STANDIN
// Function11cc850, Owner11cc850: GUESS(low) STANDIN
// Slot2, Function4e0ee0, member, padding: GUESS(low) STANDIN
#pragma once
#include "PathingDoor.h"

class Owner11cc850
{
public:
    virtual std::uint32_t Slot2() const;
    void Function4e0ee0(PathingDoorVirtualTarget* target);
    void Function11cc850(PathingDoorVirtualTarget* target);
    std::uint32_t member;
};

