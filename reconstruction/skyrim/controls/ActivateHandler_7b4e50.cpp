// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActivateHandler, ActivateHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x7b4e50 ActivateHandler::CanProcess
#include "ActivateHandler_7b4e50.h"

bool ActivateHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->activate;
}
