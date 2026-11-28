// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12b0f0 CallbackHolder12b0f0::CallbackHolder12b0f0
// Adapted bodies: none
#include "CallbackHolder12b0f0.h"

// Initializes the callback holder reference count, state, and clears its callback.
CallbackHolder12b0f0::CallbackHolder12b0f0()
    : refCount(1)
    , state(1)
    , flags(0)
{
    callback = nullptr;
}
