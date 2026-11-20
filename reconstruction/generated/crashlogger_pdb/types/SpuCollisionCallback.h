// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpuCollisionCallback; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__hkpEntity__SpuCollisionCallbackEventFilter_unsigned_char_55cc7d49.h"
struct hkSpuCollisionCallbackUtil;
struct SpuCollisionCallback {
    hkSpuCollisionCallbackUtil* util;
    unsigned short capacity;
    EnumSet_RE__hkpEntity__SpuCollisionCallbackEventFilter_unsigned_char_55cc7d49 eventFilter;
    unsigned char userFilter;
    unsigned int pad0C;
};
static_assert(sizeof(SpuCollisionCallback) == 16, "SpuCollisionCallback layout differs from the PDB");
