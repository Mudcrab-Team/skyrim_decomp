// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSwitchNode; size 0x150
#pragma once

#include "NiNode.h"
#include "NiTPrimitiveArray_unsigned_int_64ee19f4.h"
struct NiSwitchNode {
    NiNode _base;
    unsigned short flags;
    unsigned char undefined_12a[2];
    int index;
    float savedTime;
    unsigned int revID;
    NiTPrimitiveArray_unsigned_int_64ee19f4 childRevID;
};
static_assert(sizeof(NiSwitchNode) == 336, "NiSwitchNode layout differs from the PDB");
