// Source exposure: mixed (local binary analysis and public names).
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0x4e0f40 (skyrim_shared/pathfinding/PathingDoor): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// PathingDoorVirtualTarget: GUESS(low) STANDIN; vtable slots inferred from call offsets
// 0x11cc850 Owner11cc850::Function11cc850
// Slot2, member: GUESS(low) STANDIN
#include "Owner11cc850.h"

struct PathingDoorVirtualTarget
{
    virtual void Slot0();
    virtual void Slot1(std::uint32_t* value);
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11(std::uint32_t value);
};

// guess: same compiled code as matched 0x4e0f40 apart from relocated fields; its role here is not established.
void Owner11cc850::Function11cc850(PathingDoorVirtualTarget* target)
{
    target->Slot1(&member);
}
