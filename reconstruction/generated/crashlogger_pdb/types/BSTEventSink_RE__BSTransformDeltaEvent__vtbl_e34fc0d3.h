// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSTransformDeltaEvent>_vtbl; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3) == 16, "BSTEventSink_RE__BSTransformDeltaEvent__vtbl_e34fc0d3 layout differs from the PDB");
