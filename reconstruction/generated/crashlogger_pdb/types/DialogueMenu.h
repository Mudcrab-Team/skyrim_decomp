// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialogueMenu; size 0x68
#pragma once

#include "BSTArray_RE__DialogueMenu__Data_8eaff14d.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "WorldSpaceMenu.h"
struct DialogueMenu {
    WorldSpaceMenu _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    BSTArray_RE__DialogueMenu__Data_8eaff14d unk38;
};
static_assert(sizeof(DialogueMenu) == 104, "DialogueMenu layout differs from the PDB");
