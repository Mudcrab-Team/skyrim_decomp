// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SETTINGS_VALUE_VR; size 0x8
#pragma once
struct SETTINGS_VALUE_VR {
    unsigned char value_raw[4];
    unsigned char pad[4];
};
static_assert(sizeof(SETTINGS_VALUE_VR) == 8, "SETTINGS_VALUE_VR layout differs from the PDB");
