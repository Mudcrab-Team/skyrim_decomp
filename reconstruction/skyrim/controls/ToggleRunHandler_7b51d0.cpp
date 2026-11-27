// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b51d0 ToggleRunHandler::Function7b51d0
// Adapted bodies: none
#include "ToggleRunHandler_7b51d0.h"

bool ToggleRunHandler::Function7b51d0(InputEvent* event)
{
    UserEvents* events = gUserEvents;
    return event->QUserEvent().data == events->toggleRun.data;
}
