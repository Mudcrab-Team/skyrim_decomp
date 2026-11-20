// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESFastTravelEndEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESFastTravelEndEvent__vtbl_ab71f01a {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESFastTravelEndEvent__vtbl_ab71f01a) == 16, "BSTEventSink_RE__TESFastTravelEndEvent__vtbl_ab71f01a layout differs from the PDB");
