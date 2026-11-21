// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: USER_EVENT_FLAG
#pragma once
enum class USER_EVENT_FLAG : int {
    kInvalid = -2147483648,
    kAll = -1,
    kNone = 0,
    kMovement = 1,
    kLooking = 2,
    kActivate = 4,
    kMenu = 8,
    kConsole = 16,
    kPOVSwitch = 32,
    kFighting = 64,
    kSneaking = 128,
    kMainFour = 256,
    kWheelZoom = 512,
    kJumping = 1024,
    kVATS = 2048,
};
