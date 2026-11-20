// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MotionGestureEvent; size 0x38
#pragma once

#include "IDEvent.h"
struct MotionGestureEvent {
    IDEvent _base;
    int unk28;
    int unk2C;
    bool unk30;
    unsigned char pad31;
    unsigned short pad32;
    int unk34;
};
static_assert(sizeof(MotionGestureEvent) == 56, "MotionGestureEvent layout differs from the PDB");
