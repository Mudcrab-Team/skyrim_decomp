// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BGSSaveLoadManagerEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BGSSaveLoadManagerEvent__vtbl_2c3e4e93 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BGSSaveLoadManagerEvent__vtbl_2c3e4e93) == 16, "BSTEventSink_RE__BGSSaveLoadManagerEvent__vtbl_2c3e4e93 layout differs from the PDB");
