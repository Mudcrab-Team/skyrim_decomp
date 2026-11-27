// Source exposure: binary-analysis (authorized pinned-image observations).
// Code origin: original; handwritten body from authorized target observations.
// SPDX-License-Identifier: CC0-1.0
// 0x194c70 QueuedTempEffect::Function194c70
// Adapted bodies: none.
#include "QueuedTempEffect_194c70.h"

bool QueuedTempEffect::Function194c70(char* buffer, std::uint32_t capacity)
{
    bool unavailable = state != 6;
    if (unavailable) {
        strcpy_s(buffer, capacity, stateMessage);
    }
    return unavailable;
}
