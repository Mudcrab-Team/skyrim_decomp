// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSConstructFormsInAllFilesMap; size 0x80
#pragma once

#include "BGSConstructedForms.h"
#include "BSTScatterTable_RE__BSCRC32_RE__TESFile_std__equal_to_RE__TESFile_RE__BSTScatterTableTr_f80ac68b.h"
struct BGSConstructFormsInAllFilesMap {
    BSTScatterTable_RE__BSCRC32_RE__TESFile_std__equal_to_RE__TESFile_RE__BSTScatterTableTr_f80ac68b files;
    BGSConstructedForms constructedForms;
    unsigned int count;
    unsigned int pad7C;
};
static_assert(sizeof(BGSConstructFormsInAllFilesMap) == 128, "BGSConstructFormsInAllFilesMap layout differs from the PDB");
