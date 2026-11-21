// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BSGamerProfileEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BSGamerProfileEvent__vtbl_c81ef78a {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BSGamerProfileEvent__vtbl_c81ef78a) == 16, "BSTEventSink_RE__BSGamerProfileEvent__vtbl_c81ef78a layout differs from the PDB");
