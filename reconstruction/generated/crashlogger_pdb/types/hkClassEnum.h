// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClassEnum; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkFlags_hkClassEnum__FlagValues_uint32.h"
struct hkClassEnum__Item;
struct hkCustomAttributes;
struct hkClassEnum {
    char* m_name_0;
    hkClassEnum__Item* m_items_8;
    int m_numItems_10;
    char _pad_14[4];
    hkCustomAttributes* m_attributes_18;
    hkFlags_hkClassEnum__FlagValues_uint32 m_flags_20;
    char _pad_24[4];
};
static_assert(sizeof(hkClassEnum) == 40, "hkClassEnum layout differs from the PDB");
