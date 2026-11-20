// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UI_MESSAGE_TYPE
#pragma once
enum class UI_MESSAGE_TYPE : int {
    kUpdate = 0,
    kShow = 1,
    kReshow = 2,
    kHide = 3,
    kForceHide = 4,
    kScaleformEvent = 6,
    kUserEvent = 7,
    kInventoryUpdate = 8,
    kUserProfileChange = 9,
    kMUStatusChange = 10,
    kResumeCaching = 11,
    kUpdateController = 12,
    kChatterEvent = 13,
};
