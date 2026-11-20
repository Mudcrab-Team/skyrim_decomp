// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphChannel; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSIntrusiveRefCounted.h"
struct BSAnimationGraphChannel_vtbl;
struct BSAnimationGraphChannel {
    BSAnimationGraphChannel_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
    BSFixedString_char_83b572b4 channelName;
    unsigned int value;
    unsigned int pad1C;
};
static_assert(sizeof(BSAnimationGraphChannel) == 32, "BSAnimationGraphChannel layout differs from the PDB");
