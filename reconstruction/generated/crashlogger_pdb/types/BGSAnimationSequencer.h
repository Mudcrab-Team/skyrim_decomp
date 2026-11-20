// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAnimationSequencer; size 0x38
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_cdb81d81.h"
struct BGSAnimationSequencer {
    unsigned int numSequences;
    unsigned int pad04;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_cdb81d81 actions;
};
static_assert(sizeof(BGSAnimationSequencer) == 56, "BGSAnimationSequencer layout differs from the PDB");
