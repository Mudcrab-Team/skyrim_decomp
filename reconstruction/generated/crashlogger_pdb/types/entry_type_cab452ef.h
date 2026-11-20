// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: entry_type; size 0x10
// one of 7 different PDB types sharing this name
#pragma once

struct entry_type_b9160dd8;
struct entry_type_cab452ef {
    unsigned char value_data_raw[8];
    entry_type_b9160dd8* next;
};
static_assert(sizeof(entry_type_cab452ef) == 16, "entry_type_cab452ef layout differs from the PDB");
