// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IDEvent; size 0x28
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "InputEvent.h"
struct IDEvent {
    InputEvent _base;
    BSFixedString_char_83b572b4 userEvent;
    unsigned int idCode;
    unsigned int pad24;
};
static_assert(sizeof(IDEvent) == 40, "IDEvent layout differs from the PDB");
