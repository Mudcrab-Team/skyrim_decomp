// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EffectItem; size 0xc
#pragma once
struct EffectItem {
    float magnitude;
    unsigned int area;
    unsigned int duration;
};
static_assert(sizeof(EffectItem) == 12, "EffectItem layout differs from the PDB");
