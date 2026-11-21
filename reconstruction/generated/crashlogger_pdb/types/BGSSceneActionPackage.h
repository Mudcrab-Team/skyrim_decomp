// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneActionPackage; size 0x40
#pragma once

#include "BGSSceneAction.h"
#include "BSTArray_RE__TESPackage_0280bbb0.h"
struct BGSSceneActionPackage {
    BGSSceneAction _base;
    unsigned long long unk20;
    BSTArray_RE__TESPackage_0280bbb0 packages;
};
static_assert(sizeof(BGSSceneActionPackage) == 64, "BGSSceneActionPackage layout differs from the PDB");
