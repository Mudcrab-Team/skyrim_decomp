// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESLockChangedEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESLockChangedEvent__vtbl_862bd0e6 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESLockChangedEvent__vtbl_862bd0e6) == 16, "BSTEventSink_RE__TESLockChangedEvent__vtbl_862bd0e6 layout differs from the PDB");
