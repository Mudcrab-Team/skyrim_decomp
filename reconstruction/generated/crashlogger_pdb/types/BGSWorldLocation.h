// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSWorldLocation; size 0x18
#pragma once

struct TESForm;
struct BGSWorldLocation {
    unsigned char pos_raw[16];
    TESForm* space;
};
static_assert(sizeof(BGSWorldLocation) == 24, "BGSWorldLocation layout differs from the PDB");
