// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESIdleForm; size 0x68
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "IDLE_DATA.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
struct NiFormArray_60ab7697;
struct TESIdleForm_2b3518b0 {
    TESForm _base;
    TESCondition_4d3cdc88 conditions;
    IDLE_DATA data;
    unsigned short pad2E;
    NiFormArray_60ab7697* childIdles;
    TESIdleForm_2b3518b0* parentIdle;
    TESIdleForm_2b3518b0* prevIdle;
    BSFixedString_char_83b572b4 animFileName;
    BSFixedString_char_83b572b4 animEventName;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
};
static_assert(sizeof(TESIdleForm_2b3518b0) == 104, "TESIdleForm_2b3518b0 layout differs from the PDB");
