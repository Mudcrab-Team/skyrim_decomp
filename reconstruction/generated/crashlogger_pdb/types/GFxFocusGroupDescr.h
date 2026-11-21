// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxFocusGroupDescr; size 0x50
#pragma once
struct GFxFocusGroupDescr {
    unsigned char flags;
    unsigned char undefined_1[7];
    void** tabable;
    int tabableCount;
    unsigned char undefined_14[20];
    void* lastFocused;
    void* modalClip;
    unsigned short lastFocusKeyCode;
    unsigned char undefined_3a[2];
    unsigned int lastFocusRect[4];
    unsigned char focusRectShown;
    unsigned char undefined_4d[3];
};
static_assert(sizeof(GFxFocusGroupDescr) == 80, "GFxFocusGroupDescr layout differs from the PDB");
