// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimationClipDataSingleton; size 0x58
#pragma once

#include "BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_e71268b4.h"
struct AnimationClipDataSingleton_vtbl;
struct AnimationClipDataSingleton {
    AnimationClipDataSingleton_vtbl* __vftable;
    unsigned long long field_8;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_e71268b4 anim_datas;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 mb_hkxFiles;
};
static_assert(sizeof(AnimationClipDataSingleton) == 88, "AnimationClipDataSingleton layout differs from the PDB");
