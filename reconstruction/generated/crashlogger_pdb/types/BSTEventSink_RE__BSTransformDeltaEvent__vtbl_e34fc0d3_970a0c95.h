// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSTransformDeltaEvent>_vtbl; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BSEventNotifyControl.h"
struct Event;
struct BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3_970a0c95 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(Event* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3_970a0c95) == 16, "BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3_970a0c95 layout differs from the PDB");
