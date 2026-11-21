// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Setting; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct Setting_vtbl;
struct Setting {
    Setting_vtbl* __vftable;
    unsigned char data[8];  // Data is 20 bytes in the PDB, more than this slot
    unsigned char* name;
};
static_assert(sizeof(Setting) == 24, "Setting layout differs from the PDB");
