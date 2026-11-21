// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CustomColor; size 0x4
#pragma once
struct CustomColor {
    float contribution;
};
static_assert(sizeof(CustomColor) == 4, "CustomColor layout differs from the PDB");
