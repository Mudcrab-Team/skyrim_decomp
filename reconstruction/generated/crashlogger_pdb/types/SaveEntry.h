// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SaveEntry; size 0x48
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_0001a18c.h"
struct SaveEntry {
    unsigned int characterID;
    unsigned int isModded;
    unsigned int manualSaveCount;
    unsigned int autoSaveCount;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_0001a18c autoSaves;
    BSFixedString_char_83b572b4 lastQuicksave;
};
static_assert(sizeof(SaveEntry) == 72, "SaveEntry layout differs from the PDB");
