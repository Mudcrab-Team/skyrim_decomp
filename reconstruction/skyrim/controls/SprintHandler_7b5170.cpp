// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b5170 SprintHandler::Function7b5170
// Adapted bodies: none
#include "SprintHandler_7b5170.h"

bool SprintHandler::Function7b5170(InputEvent* event)
{
    UserEvents* events = gUserEvents;
    return event->QUserEvent().data == events->sprint.data;
}
