// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// TogglePOVHandler, TogglePOVHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x7b51a0 TogglePOVHandler::CanProcess
#include "TogglePOVHandler_7b51a0.h"

bool TogglePOVHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->togglePOV;
}
