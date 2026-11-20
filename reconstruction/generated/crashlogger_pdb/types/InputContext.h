// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InputContext; size 0x60
#pragma once
struct InputContext {
    unsigned char deviceMappings_raw[96];
};
static_assert(sizeof(InputContext) == 96, "InputContext layout differs from the PDB");
