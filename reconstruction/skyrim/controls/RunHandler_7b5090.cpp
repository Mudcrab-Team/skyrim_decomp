// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x7b5090 RunHandler::CanProcess
// RunHandler::CanProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
#include "RunHandler_7b5090.h"

bool RunHandler::CanProcess(InputEvent* event)
{
    UserEvents* events = g_userEvents;
    return event->QUserEvent()._data == events->run._data;
}
