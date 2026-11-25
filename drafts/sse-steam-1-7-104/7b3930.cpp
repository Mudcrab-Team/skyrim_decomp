// Near miss: 30.23% | inline-set
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; handwritten body from authorized target observations.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// 0x7b3930 RunHandler::ProcessButton

#include "include/7b3930/RunHandler_7b3930.h"

void RunHandler::ProcessButton(ButtonEvent* event, PlayerControlsData* data)
{
    if ((event->value != 0.0f && event->heldDownSecs == 0.0f) ||
        (event->value == 0.0f && event->heldDownSecs >= 0.0f)) {
        data->running = !data->running;
    }
}
