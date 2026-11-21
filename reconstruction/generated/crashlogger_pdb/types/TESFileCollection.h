// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFileCollection; size 0x30
#pragma once

#include "BSTArray_RE__TESFile_da0f8183.h"
struct TESFileCollection {
    BSTArray_RE__TESFile_da0f8183 files;
    BSTArray_RE__TESFile_da0f8183 smallFiles;
};
static_assert(sizeof(TESFileCollection) == 48, "TESFileCollection layout differs from the PDB");
