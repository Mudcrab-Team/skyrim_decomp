// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ButtonEvent; size 0x30
#pragma once

#include "IDEvent.h"
struct ButtonEvent {
    IDEvent _base;
    float value;
    float heldDownSecs;
};
static_assert(sizeof(ButtonEvent) == 48, "ButtonEvent layout differs from the PDB");
