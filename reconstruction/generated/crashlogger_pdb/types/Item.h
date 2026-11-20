// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Item; size 0x18
#pragma once
struct Item {
    unsigned char undefined_0[8];
    unsigned char* m_name;
    unsigned char undefined_10[8];
};
static_assert(sizeof(Item) == 24, "Item layout differs from the PDB");
