// Source exposure: binary-analysis (sizes and the inlined destructor body from the pinned image listing; the class name from the sibling lead).
// SPDX-License-Identifier: CC0-1.0
// CombatTargetReservation: SIBLING(fo4-private@1b765c70, author-permission); the image carries no RTTI for this vftable, so the name is only the sibling's
// CombatTargetReservationEntry: GUESS(low); the unknown 8-byte head and the member at 0x08 whose destructor stays out of line
#pragma once

class CombatTargetReservationEntry
{
public:
    ~CombatTargetReservationEntry();

    unsigned char unk00[0x18];  // 00
};

class CombatTargetReservation
{
public:
    CombatTargetReservation();
    virtual ~CombatTargetReservation() = default;  // 00

    CombatTargetReservationEntry unk08;  // 08
};
static_assert(sizeof(CombatTargetReservation) == 0x20, "size from the deleting destructor");
