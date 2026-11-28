// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ClickHandler, ClickHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x962000 ClickHandler::CanProcess
#include "ClickHandler_962000.h"

bool ClickHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->clickEvent;
}
