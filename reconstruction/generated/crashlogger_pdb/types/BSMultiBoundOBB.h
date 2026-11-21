// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBoundOBB; size 0x68
#pragma once

#include "BSMultiBoundAABB.h"
#include "NiMatrix3.h"
struct BSMultiBoundOBB {
    BSMultiBoundAABB _base;
    NiMatrix3 rotation;
    bool unk64;
    unsigned char pad65;
    unsigned short pad66;
};
static_assert(sizeof(BSMultiBoundOBB) == 104, "BSMultiBoundOBB layout differs from the PDB");
