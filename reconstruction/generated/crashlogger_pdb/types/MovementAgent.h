// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementAgent; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IMovementState;
struct MovementAgent_vtbl;
struct MovementAgent {
    MovementAgent_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    IMovementState* movementState;
};
static_assert(sizeof(MovementAgent) == 24, "MovementAgent layout differs from the PDB");
