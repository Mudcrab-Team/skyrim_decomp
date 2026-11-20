// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::DefaultObjectsReadyEvent::Event>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__DefaultObjectsReadyEvent__Event__vtbl_b88fff4d {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__DefaultObjectsReadyEvent__Event__vtbl_b88fff4d) == 16, "BSTEventSink_RE__DefaultObjectsReadyEvent__Event__vtbl_b88fff4d layout differs from the PDB");
