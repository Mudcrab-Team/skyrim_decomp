// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GamepadData; size 0x78
#pragma once

#include "TouchPadData.h"
#include "UnusedExtensionData.h"
#include "Vector3.h"
#include "Vector4.h"
struct GamepadData {
    unsigned int buttonState;
    unsigned char rawLeftStickX;
    unsigned char rawLeftStickY;
    unsigned char rawRightStickX;
    unsigned char rawRightStickY;
    unsigned char rawLeftTrigger;
    unsigned char rawRightTrigger;
    unsigned char pad0A[2];
    Vector4 orientation;
    Vector3 acceleration;
    Vector3 angularVelocity;
    TouchPadData touchPadData;
    bool padConnected;
    unsigned char pad4D[3];
    unsigned long long timestamp;
    UnusedExtensionData unusedExtData;
    unsigned char connectedCount;
    unsigned char pad69[2];
    unsigned char specialDataLen;
    unsigned char specialData[12];
};
static_assert(sizeof(GamepadData) == 120, "GamepadData layout differs from the PDB");
