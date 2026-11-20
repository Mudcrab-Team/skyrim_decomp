// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESTopicInfoEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESTopicInfoEvent__vtbl_be18a162 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESTopicInfoEvent__vtbl_be18a162) == 16, "BSTEventSink_RE__TESTopicInfoEvent__vtbl_be18a162 layout differs from the PDB");
