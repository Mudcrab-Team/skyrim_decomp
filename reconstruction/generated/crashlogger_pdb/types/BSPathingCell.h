// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingCell; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
struct BSPathingCell_vtbl;
struct BSPathingCell {
    BSPathingCell_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
};
static_assert(sizeof(BSPathingCell) == 16, "BSPathingCell layout differs from the PDB");
