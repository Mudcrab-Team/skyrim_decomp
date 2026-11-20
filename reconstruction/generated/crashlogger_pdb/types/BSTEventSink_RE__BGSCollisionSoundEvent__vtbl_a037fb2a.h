// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::BGSCollisionSoundEvent>_vtbl; size 0x10
#pragma once

#include "BSEventNotifyControl.h"
struct BSTEventSink_RE__BGSCollisionSoundEvent__vtbl_a037fb2a {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(char32_t* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__BGSCollisionSoundEvent__vtbl_a037fb2a) == 16, "BSTEventSink_RE__BGSCollisionSoundEvent__vtbl_a037fb2a layout differs from the PDB");
