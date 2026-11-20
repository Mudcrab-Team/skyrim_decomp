// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RE::BSTEventSink<RE::BSScript::LogEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct RE__BSTEventSink_RE__BSScript__LogEvent__vtbl_cac6f655 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(RE__BSTEventSink_RE__BSScript__LogEvent__vtbl_cac6f655) == 16, "RE__BSTEventSink_RE__BSScript__LogEvent__vtbl_cac6f655 layout differs from the PDB");
