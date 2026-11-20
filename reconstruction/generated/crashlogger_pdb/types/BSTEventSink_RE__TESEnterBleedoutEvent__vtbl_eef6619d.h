// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESEnterBleedoutEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESEnterBleedoutEvent__vtbl_eef6619d {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESEnterBleedoutEvent__vtbl_eef6619d) == 16, "BSTEventSink_RE__TESEnterBleedoutEvent__vtbl_eef6619d layout differs from the PDB");
