// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSink<RE::bhkCharacterMoveFinishEvent>_vtbl; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BSEventNotifyControl.h"
struct Event;
struct BSTEventSink_RE__bhkCharacterMoveFinishEvent__vtbl_de2f209f_ea02831b {
    void (*_dtor_BSTEventSink)(void);
    BSEventNotifyControl (*ProcessEvent)(Event* , char32_t* );
};
static_assert(sizeof(BSTEventSink_RE__bhkCharacterMoveFinishEvent__vtbl_de2f209f_ea02831b) == 16, "BSTEventSink_RE__bhkCharacterMoveFinishEvent__vtbl_de2f209f_ea02831b layout differs from the PDB");
