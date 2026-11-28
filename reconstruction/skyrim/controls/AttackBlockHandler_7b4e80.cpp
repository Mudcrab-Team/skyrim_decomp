// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AttackBlockHandler, AttackBlockHandler::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x7b4e80 AttackBlockHandler::CanProcess
#include "AttackBlockHandler_7b4e80.h"

// Checks whether the input event matches leftAttack or rightAttack.
bool AttackBlockHandler::CanProcess(InputEvent* a_event)
{
    if (a_event->QUserEvent() == UserEvents::GetSingleton()->leftAttack)
    {
        return true;
    }
    if (a_event->QUserEvent() == UserEvents::GetSingleton()->rightAttack)
    {
        return true;
    }
    return false;
}
