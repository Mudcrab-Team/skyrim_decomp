// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x962060 DirectionHandler::CanProcess
#include "DirectionHandler_962060.h"

// Returns true when the input event matches one of the five directional menu events.
bool DirectionHandler::CanProcess(InputEvent* event)
{
    if (event->QUserEvent() == UserEvents::singleton->up)
    {
        return true;
    }
    if (event->QUserEvent() == UserEvents::singleton->down)
    {
        return true;
    }
    if (event->QUserEvent() == UserEvents::singleton->left)
    {
        return true;
    }
    if (event->QUserEvent() == UserEvents::singleton->right)
    {
        return true;
    }
    if (event->QUserEvent() == UserEvents::singleton->look)
    {
        return true;
    }
    return false;
}
