// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AutoMoveHandler, CanProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
// 0x7b4ee0 AutoMoveHandler::CanProcess
#include "AutoMoveHandler_7b4ee0.h"

bool AutoMoveHandler::CanProcess(InputEvent* a_event)
{
    UserEvents* events = userEvents;
    return a_event->QUserEvent().data == events->autoMove.data;
}
