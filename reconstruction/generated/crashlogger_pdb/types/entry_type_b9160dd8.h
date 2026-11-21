// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: entry_type; size 0x18
// one of 7 different PDB types sharing this name
#pragma once
struct entry_type_b9160dd8 {
    unsigned char value_data_raw[8];
    entry_type_b9160dd8* next;
    entry_type_b9160dd8* next_2;
};
static_assert(sizeof(entry_type_b9160dd8) == 24, "entry_type_b9160dd8 layout differs from the PDB");
