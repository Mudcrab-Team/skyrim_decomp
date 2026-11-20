// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSAnimationGraphEvent>_vtbl; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f_f9d5ba84 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f_f9d5ba84) == 16, "BSTEventSink_RE__BSAnimationGraphEvent__vtbl_40d1bd3f_f9d5ba84 layout differs from the PDB");
