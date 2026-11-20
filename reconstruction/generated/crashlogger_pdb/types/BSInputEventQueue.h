// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSInputEventQueue; size 0x20
#pragma once

#include "BSTSingletonSDM_RE__BSInputEventQueue_89b0afed.h"
struct BSInputEventQueue {
    BSTSingletonSDM_RE__BSInputEventQueue_89b0afed _base;
    unsigned char pad001;
    unsigned short pad002;
    unsigned int buttonEventCount;
    unsigned int charEventCount;
    unsigned int mouseEventCount;
    unsigned int thumbstickEventCount;
    unsigned int connectEventCount;
    unsigned int kinectEventCount;
    unsigned int pad01C;
};
static_assert(sizeof(BSInputEventQueue) == 32, "BSInputEventQueue layout differs from the PDB");
