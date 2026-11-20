// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ThumbstickEvent; size 0x30
#pragma once

#include "IDEvent.h"
struct ThumbstickEvent {
    IDEvent _base;
    float xValue;
    float yValue;
};
static_assert(sizeof(ThumbstickEvent) == 48, "ThumbstickEvent layout differs from the PDB");
