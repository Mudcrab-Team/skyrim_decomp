// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SCRIPT_EFFECT_DATA; size 0x8
#pragma once
struct SCRIPT_EFFECT_DATA {
    bool scriptEffectStart;
    bool scriptEffectFinish;
    unsigned short pad02;
    float secondsElapsed;
};
static_assert(sizeof(SCRIPT_EFFECT_DATA) == 8, "SCRIPT_EFFECT_DATA layout differs from the PDB");
