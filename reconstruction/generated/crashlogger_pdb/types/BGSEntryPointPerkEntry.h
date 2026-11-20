// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointPerkEntry; size 0x30
#pragma once

#include "BGSPerkEntry.h"
#include "EntryData.h"
#include "SimpleArray_RE__TESCondition_232c78c1.h"
struct BGSEntryPointFunctionData;
struct BGSPerk_dfc65d7f;
struct BGSEntryPointPerkEntry {
    BGSPerkEntry _base;
    EntryData entryData;
    BGSEntryPointFunctionData* functionData;
    SimpleArray_RE__TESCondition_232c78c1 conditions;
    BGSPerk_dfc65d7f* perk;
};
static_assert(sizeof(BGSEntryPointPerkEntry) == 48, "BGSEntryPointPerkEntry layout differs from the PDB");
