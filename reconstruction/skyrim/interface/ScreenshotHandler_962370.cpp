// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScreenshotHandler, ScreenshotHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x962370 ScreenshotHandler::CanProcess
#include "ScreenshotHandler_962370.h"

// Checks whether the input event matches the screenshot or multi-screenshot binding.
bool ScreenshotHandler::CanProcess(InputEvent* a_event)
{
    if (a_event->QUserEvent() == UserEvents::GetSingleton()->screenshot)
    {
        return true;
    }
    if (a_event->QUserEvent() == UserEvents::GetSingleton()->multiScreenshot)
    {
        return true;
    }
    return false;
}
