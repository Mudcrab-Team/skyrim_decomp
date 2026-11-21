// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::TESSpellCastEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__TESSpellCastEvent__vtbl_8bc03e2b {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__TESSpellCastEvent__vtbl_8bc03e2b) == 16, "BSTEventSink_RE__TESSpellCastEvent__vtbl_8bc03e2b layout differs from the PDB");
