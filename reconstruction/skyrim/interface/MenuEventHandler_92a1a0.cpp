// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x92a1a0 MenuEventHandler::CanProcess
#include "MenuEventHandler_92a1a0.h"

// Return whether the input event matches the handler's menu event name.
bool MenuEventHandler::CanProcess(InputEvent* a_event)
{
    return a_event->QUserEvent() == gUserEvents->unk180;
}
