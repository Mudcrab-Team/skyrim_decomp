// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementArbiter; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IMovementState;
struct MovementArbiter_vtbl;
struct MovementArbiter {
    MovementArbiter_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    IMovementState* movementState;
};
static_assert(sizeof(MovementArbiter) == 24, "MovementArbiter layout differs from the PDB");
