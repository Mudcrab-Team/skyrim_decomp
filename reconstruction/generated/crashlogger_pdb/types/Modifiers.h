// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Modifiers; size 0xc
#pragma once
struct Modifiers {
    float modifiers[3];
};
static_assert(sizeof(Modifiers) == 12, "Modifiers layout differs from the PDB");
