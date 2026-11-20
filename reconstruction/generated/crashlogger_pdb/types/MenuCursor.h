// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuCursor; size 0x30
#pragma once

#include "BSTSingletonSDM_RE__MenuCursor_4f6d22be.h"
struct MenuCursor {
    BSTSingletonSDM_RE__MenuCursor_4f6d22be _base;
    unsigned char pad01;
    unsigned short pad02;
    float cursorPosX;
    float cursorPosY;
    float safeZoneX;
    float safeZoneY;
    float screenWidthX;
    float screenWidthY;
    float cursorSensitivity;
    float unk20;
    float unk24;
    float defaultMouseSpeed;
    int showCursorCount;
};
static_assert(sizeof(MenuCursor) == 48, "MenuCursor layout differs from the PDB");
