// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClassEnum; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

struct Item;
struct hkCustomAttributes_7007198f;
struct hkClassEnum_c1f7e791 {
    unsigned char* m_name;
    Item* m_items;
    int m_numItems;
    int pad14;
    hkCustomAttributes_7007198f* m_attributes;
    unsigned char m_flags_raw[8];
};
static_assert(sizeof(hkClassEnum_c1f7e791) == 40, "hkClassEnum_c1f7e791 layout differs from the PDB");
