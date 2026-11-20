// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementActorAvoidanceParameters; size 0x20
#pragma once

#include "BSTArray_unsigned_int_RE__BSTSmallArrayHeapAllocator_4_cc1ae2ad.h"
#include "enumeration_RE__MovementActorAvoidanceParameters__Type_unsigned_int_329d96b1.h"
struct MovementActorAvoidanceParameters {
    BSTArray_unsigned_int_RE__BSTSmallArrayHeapAllocator_4_cc1ae2ad actors;
    enumeration_RE__MovementActorAvoidanceParameters__Type_unsigned_int_329d96b1 flags;
    int field_1C;
};
static_assert(sizeof(MovementActorAvoidanceParameters) == 32, "MovementActorAvoidanceParameters layout differs from the PDB");
