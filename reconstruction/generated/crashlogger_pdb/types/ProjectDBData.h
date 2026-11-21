// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ProjectDBData; size 0x100
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_char_1b5becfd.h"
#include "BSTScatterTable_RE__BSCRC32_char_std__equal_to_char_RE__BSTScatterTableTraits_char_int_c006a338.h"
struct ProjectDBData {
    void* vtbl;
    unsigned char unk08[104];
    BSTScatterTable_RE__BSCRC32_char_std__equal_to_char_RE__BSTScatterTableTraits_char_int_c006a338 unk70;
    BSTScatterTable_RE__BSCRC32_char_std__equal_to_char_RE__BSTScatterTableTraits_char_int_c006a338 unkA0;
    BSTArray_char_1b5becfd unkD0;
    BSTArray_char_1b5becfd unkE8;
};
static_assert(sizeof(ProjectDBData) == 256, "ProjectDBData layout differs from the PDB");
