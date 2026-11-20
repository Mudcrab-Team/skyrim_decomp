// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBoundAABB; size 0x40
#pragma once

#include "BSMultiBoundShape.h"
#include "NiPoint3.h"
struct BSMultiBoundAABB {
    BSMultiBoundShape _base;
    unsigned int pad18;
    NiPoint3 center;
    unsigned int pad28;
    NiPoint3 size;
    unsigned int pad38;
    unsigned int pad3C;
};
static_assert(sizeof(BSMultiBoundAABB) == 64, "BSMultiBoundAABB layout differs from the PDB");
