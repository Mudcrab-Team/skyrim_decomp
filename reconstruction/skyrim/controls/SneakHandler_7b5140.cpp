// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x7b5140 SneakHandler::CanProcess
// SneakHandler::CanProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
#include "SneakHandler_7b5140.h"

bool SneakHandler::CanProcess(InputEvent* event)
{
    UserEvents* events = g_userEvents;
    return event->QUserEvent()._data == events->sneak._data;
}
