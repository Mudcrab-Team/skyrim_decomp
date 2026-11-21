// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DirectionHandler; size 0x30
#pragma once

#include "MenuEventHandler.h"
struct DirectionHandler {
    MenuEventHandler _base;
    float nextRepeat;
    float menuKeyRepeatLong;
    float menuKeyRepeatShort;
    unsigned int repeatTimer;
    unsigned int currentRepeatCount;
    unsigned int longRepeatThresholdCount;
    bool repeatEnabled;
    bool unk29;
    unsigned char pad2A;
    unsigned char undefined_2b[1];
    unsigned short pad2B;
    unsigned char undefined_2e[2];
};
static_assert(sizeof(DirectionHandler) == 48, "DirectionHandler layout differs from the PDB");
