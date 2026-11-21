// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkStepInfo; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkStepInfo {
    float startTime;
    float endTime;
    float deltaTime;
    float invDeltaTime;
};
static_assert(sizeof(hkStepInfo) == 16, "hkStepInfo layout differs from the PDB");
