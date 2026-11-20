// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingRequest; size 0x100
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSPathingActorAttributes.h"
#include "BSPathingGoal.h"
#include "BSPathingRestrictions.h"
#include "BSPathingStart.h"
#include "BSTSmartPointer_RE__IMovementParameters_545c180d.h"
#include "MovementActorAvoidanceParameters.h"
struct BSPathingRequest_vtbl;
struct BSPathingRequest {
    BSPathingRequest_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    BSPathingStart start;
    BSPathingGoal goal;
    BSPathingRestrictions restrictions;
    unsigned char searchParameters_raw[16];
    BSPathingActorAttributes actorAttributes;
    MovementActorAvoidanceParameters movementActorAvoidanceParameters;
    BSTSmartPointer_RE__IMovementParameters_545c180d defaultParameters;
};
static_assert(sizeof(BSPathingRequest) == 256, "BSPathingRequest layout differs from the PDB");
