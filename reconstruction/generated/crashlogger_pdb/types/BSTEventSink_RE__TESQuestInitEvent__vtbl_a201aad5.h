// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESQuestInitEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESQuestInitEvent__vtbl_a201aad5 {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESQuestInitEvent__vtbl_a201aad5) == 16, "BSTEventSink_RE__TESQuestInitEvent__vtbl_a201aad5 layout differs from the PDB");
