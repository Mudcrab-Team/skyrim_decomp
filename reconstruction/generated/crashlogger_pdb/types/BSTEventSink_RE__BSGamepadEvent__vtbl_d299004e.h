// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSGamepadEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BSGamepadEvent__vtbl_d299004e {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSGamepadEvent__vtbl_d299004e) == 16, "BSTEventSink_RE__BSGamepadEvent__vtbl_d299004e layout differs from the PDB");
