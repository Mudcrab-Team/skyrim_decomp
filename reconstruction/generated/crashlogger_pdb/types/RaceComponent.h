// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RaceComponent; size 0x28
#pragma once

struct RaceMenuSlider;
struct TESRace;
struct RaceComponent {
    TESRace* race;
    RaceMenuSlider* sliders_data;
    unsigned char undefined_10[16];
    unsigned int unk20;
    unsigned char undefined_24[4];
};
static_assert(sizeof(RaceComponent) == 40, "RaceComponent layout differs from the PDB");
