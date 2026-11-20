// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::MenuModeChangeEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__MenuModeChangeEvent__vtbl_925d0c09 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__MenuModeChangeEvent__vtbl_925d0c09) == 16, "BSTEventSink_RE__MenuModeChangeEvent__vtbl_925d0c09 layout differs from the PDB");
