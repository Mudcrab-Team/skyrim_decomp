// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingDoor; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
struct BSPathingDoor_vtbl;
struct BSPathingDoor {
    BSPathingDoor_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
};
static_assert(sizeof(BSPathingDoor) == 16, "BSPathingDoor layout differs from the PDB");
