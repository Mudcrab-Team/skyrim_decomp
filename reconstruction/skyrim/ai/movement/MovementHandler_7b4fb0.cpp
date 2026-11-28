// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x7b4fb0 MovementHandler::CanProcess
#include "MovementHandler_7b4fb0.h"

// Checks whether the input event corresponds to any directional movement binding.
bool MovementHandler::CanProcess(InputEvent* event)
{
    if (event->QUserEvent() == UserEvents::singleton->forward ||
        event->QUserEvent() == UserEvents::singleton->back ||
        event->QUserEvent() == UserEvents::singleton->strafeLeft ||
        event->QUserEvent() == UserEvents::singleton->strafeRight ||
        event->QUserEvent() == UserEvents::singleton->move)
    {
        return true;
    }
    return false;
}
