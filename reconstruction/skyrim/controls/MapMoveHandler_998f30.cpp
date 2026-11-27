// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x998f30 MapMoveHandler::Function998f30
// Adapted bodies: none
#include "MapMoveHandler_998f30.h"

bool MapMoveHandler::Function998f30(InputEvent* event)
{
    UserEvents* events = gUserEvents;
    return events->cursor.data == event->QUserEvent().data;
}
