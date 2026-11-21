// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESResolveNPCTemplatesEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESResolveNPCTemplatesEvent__vtbl_b65c5cef {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESResolveNPCTemplatesEvent__vtbl_b65c5cef) == 16, "BSTEventSink_RE__TESResolveNPCTemplatesEvent__vtbl_b65c5cef layout differs from the PDB");
