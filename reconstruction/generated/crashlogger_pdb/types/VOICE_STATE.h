// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VOICE_STATE
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class VOICE_STATE : int {
    kNone = 0,
    kRequest = 1,
    kStart = 2,
    kContinue = 3,
    kPrecast = 4,
    kPostcast = 5,
    kFail = 6,
};
