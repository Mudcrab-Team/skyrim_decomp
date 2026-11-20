// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraEditorID; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSFixedString_char_83b572b4.h"
struct ExtraEditorID {
    BSExtraData_4ca6af76 _base;
    BSFixedString_char_83b572b4 editorID;
};
static_assert(sizeof(ExtraEditorID) == 24, "ExtraEditorID layout differs from the PDB");
