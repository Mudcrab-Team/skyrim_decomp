// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12a5b0 CallbackEntry12a5b0::CallbackEntry12a5b0
// Adapted bodies: none
#include "CallbackEntry12a5b0.h"

// Default-initializes the callback entry id and clears its callback functor.
CallbackEntry12a5b0::CallbackEntry12a5b0()
{
    id = 0;
    callback = nullptr;
}
