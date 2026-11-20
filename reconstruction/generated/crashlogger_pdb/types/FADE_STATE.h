// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FADE_STATE
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class FADE_STATE : int {
    FADE_STATE__kNormal = 0,
    FADE_STATE__kIn = 1,
    FADE_STATE__kOut = 2,
    FADE_STATE__kTeleportIn = 3,
    FADE_STATE__kTeleportOut = 4,
    FADE_STATE__kOutDisable = 5,
    FADE_STATE__kOutDelete = 6,
};
