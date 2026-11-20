// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MouseMoveEvent; size 0x30
#pragma once

#include "IDEvent.h"
struct MouseMoveEvent {
    IDEvent _base;
    int mouseInputX;
    int mouseInputY;
};
static_assert(sizeof(MouseMoveEvent) == 48, "MouseMoveEvent layout differs from the PDB");
