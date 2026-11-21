// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__EventActionData; size 0x20
#pragma once

#include "TESPackage__TopicData.h"
struct TESIdleForm;
struct TESPackage__EventActionData {
    int EventActionType_8;
    char _pad_C[4];
    TESPackage__TopicData Topic_10;
    TESIdleForm* Idle_0;
};
static_assert(sizeof(TESPackage__EventActionData) == 32, "TESPackage__EventActionData layout differs from the PDB");
