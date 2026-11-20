// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbEvent; size 0x18
#pragma once

#include "hkbEventBase.h"
struct hkbNode_beab977b;
struct hkbEvent {
    hkbEventBase _base;
    hkbNode_beab977b* sender;
};
static_assert(sizeof(hkbEvent) == 24, "hkbEvent layout differs from the PDB");
