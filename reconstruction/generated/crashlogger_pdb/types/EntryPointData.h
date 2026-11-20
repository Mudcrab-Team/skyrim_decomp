// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EntryPointData; size 0x10
#pragma once

#include "DisabledEntryPoint.h"
struct BGSKeyword;
struct EntryPointData {
    unsigned int entryPoint;
    DisabledEntryPoint disabledEntryPoints;
    BGSKeyword* keyword;
};
static_assert(sizeof(EntryPointData) == 16, "EntryPointData layout differs from the PDB");
