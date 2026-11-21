// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxMouseState; size 0x30
#pragma once
struct GFxMouseState {
    void* topmost;
    void* previousTopmost;
    unsigned char undefined_10[8];
    unsigned int buttons;
    unsigned int prevButtons;
    float x;
    float y;
    unsigned int cursorType;
    unsigned char flags;
    unsigned char undefined_2d[3];
};
static_assert(sizeof(GFxMouseState) == 48, "GFxMouseState layout differs from the PDB");
