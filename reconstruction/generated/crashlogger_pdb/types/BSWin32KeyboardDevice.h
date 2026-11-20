// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWin32KeyboardDevice; size 0x370
#pragma once

#include "BSKeyboardDevice.h"
struct IDirectInput8A;
struct BSWin32KeyboardDevice {
    BSKeyboardDevice _base;
    IDirectInput8A* dInputDevice;
    unsigned char diObjData_raw[240];
    unsigned char prevState[256];
    unsigned char curState[256];
    bool capsLockOn;
    unsigned char undefined_369[7];
};
static_assert(sizeof(BSWin32KeyboardDevice) == 880, "BSWin32KeyboardDevice layout differs from the PDB");
