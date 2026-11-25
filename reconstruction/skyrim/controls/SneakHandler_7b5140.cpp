// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b5140 SneakHandler::CanProcess
// SneakHandler::CanProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
#include "SneakHandler_7b5140.h"

bool SneakHandler::CanProcess(InputEvent* event)
{
    UserEvents* events = g_userEvents;
    return event->QUserEvent()._data == events->sneak._data;
}
