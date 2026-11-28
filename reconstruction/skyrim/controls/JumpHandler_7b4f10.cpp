// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x7b4f10 JumpHandler::CanProcess
#include "JumpHandler_7b4f10.h"

// Return whether the input event matches the configured jump user event.
bool JumpHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->jump;
}
