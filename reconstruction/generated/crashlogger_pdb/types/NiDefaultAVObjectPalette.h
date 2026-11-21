// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiDefaultAVObjectPalette; size 0x48
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_2bcfe24c.h"
#include "NiAVObjectPalette.h"
struct NiAVObject;
struct NiDefaultAVObjectPalette {
    NiAVObjectPalette _base;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_2bcfe24c paletteMap;
    NiAVObject* scene;
};
static_assert(sizeof(NiDefaultAVObjectPalette) == 72, "NiDefaultAVObjectPalette layout differs from the PDB");
