// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScreenshotHandler; size 0x18
#pragma once

#include "MenuEventHandler.h"
struct ScreenshotHandler {
    MenuEventHandler _base;
    bool screenshotQueued;
    bool multiScreenshotQueued;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(ScreenshotHandler) == 24, "ScreenshotHandler layout differs from the PDB");
