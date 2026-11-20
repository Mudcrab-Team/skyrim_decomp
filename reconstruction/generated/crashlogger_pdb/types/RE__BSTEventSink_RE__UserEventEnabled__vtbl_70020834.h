// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RE::BSTEventSink<RE::UserEventEnabled>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct RE__BSTEventSink_RE__UserEventEnabled__vtbl_70020834 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(RE__BSTEventSink_RE__UserEventEnabled__vtbl_70020834) == 16, "RE__BSTEventSink_RE__UserEventEnabled__vtbl_70020834 layout differs from the PDB");
