// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSAnimationGraphEvent>_vtbl; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSEventNotifyControl.h"
struct Event;
struct BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(Event* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f) == 16, "BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f layout differs from the PDB");
