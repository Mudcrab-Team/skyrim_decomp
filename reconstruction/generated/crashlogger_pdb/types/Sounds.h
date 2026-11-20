// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Sounds; size 0x8
#pragma once

struct CreatureSounds;
struct Sounds {
    CreatureSounds* creatureSounds;
};
static_assert(sizeof(Sounds) == 8, "Sounds layout differs from the PDB");
