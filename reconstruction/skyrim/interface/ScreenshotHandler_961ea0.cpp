// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: AutoMemContext::AutoMemContext, AutoMemContext::~AutoMemContext, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019
// SPDX-License-Identifier: CC0-1.0
// ScreenshotHandler, ScreenshotHandler::ProcessButton, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x147420 AutoMemContext::~AutoMemContext
// 0x961ea0 ScreenshotHandler::ProcessButton
#include "ScreenshotHandler_961ea0.h"

// Restores the saved thread-local memory context identifier.
AutoMemContext::~AutoMemContext()
{
    gTlsScopeId = saved;
}

// Queues a single or multi screenshot on an initial button press.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool ScreenshotHandler::ProcessButton(ButtonEvent* a_event)
{
    AutoMemContext scope(0x46);
    if (a_event->value != 0.0f && a_event->heldDownSecs == 0.0f)
    {
        screenshotQueued = (a_event->QUserEvent() == UserEvents::GetSingleton()->screenshot);
        multiScreenshotQueued = (a_event->QUserEvent() == UserEvents::GetSingleton()->multiScreenshot);
        return true;
    }
    return false;
}
