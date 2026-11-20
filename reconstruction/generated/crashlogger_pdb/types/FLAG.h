// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FLAG
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class FLAG : int {
    kNone = 0,
    kTriggerVolume = 1,
    kSensor = 2,
    kNavmeshObstacle = 4,
};
