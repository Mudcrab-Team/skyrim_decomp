// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InputEvent; size 0x18
#pragma once

#include "INPUT_EVENT_TYPE.h"
struct InputEvent_vtbl;
struct InputEvent {
    InputEvent_vtbl* __vftable;
    int device;
    INPUT_EVENT_TYPE eventType;
    InputEvent* next;
};
static_assert(sizeof(InputEvent) == 24, "InputEvent layout differs from the PDB");
