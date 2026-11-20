// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxKeyboardState; size 0x688
#pragma once

#include "GRefCountBaseNTS_RE__GFxKeyboardState_326_f5c0697d.h"
#include "KeyQueue.h"
struct IListener;
struct GFxKeyboardState {
    GRefCountBaseNTS_RE__GFxKeyboardState_326_f5c0697d _base;
    IListener* listener;
    KeyQueue keyQueue;
    unsigned char keyboardIndex;
    unsigned char keymap[29];
    bool toggled[3];
    unsigned char pad685;
    unsigned char pad686;
    unsigned char pad687;
};
static_assert(sizeof(GFxKeyboardState) == 1672, "GFxKeyboardState layout differs from the PDB");
