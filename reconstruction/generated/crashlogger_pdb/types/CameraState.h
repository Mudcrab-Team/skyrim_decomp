// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CameraState
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class CameraState : int {
    kFirstPerson = 0,
    kAutoVanity = 1,
    kVATS = 2,
    kFree = 3,
    kIronSights = 4,
    kFurniture = 5,
    kPCTransition = 6,
    kTween = 7,
    kAnimated = 8,
    kThirdPerson = 9,
    kMount = 10,
    kBleedout = 11,
    kDragon = 12,
    kTotal = 13,
    kVRTotal = 14,
};
