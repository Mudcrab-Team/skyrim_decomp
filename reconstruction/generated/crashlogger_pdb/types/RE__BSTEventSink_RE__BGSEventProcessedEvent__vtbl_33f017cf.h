// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RE::BSTEventSink<RE::BGSEventProcessedEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct RE__BSTEventSink_RE__BGSEventProcessedEvent__vtbl_33f017cf {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(RE__BSTEventSink_RE__BGSEventProcessedEvent__vtbl_33f017cf) == 16, "RE__BSTEventSink_RE__BGSEventProcessedEvent__vtbl_33f017cf layout differs from the PDB");
