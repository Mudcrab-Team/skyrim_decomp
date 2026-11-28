// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit1fb4a0::ClearBuffers1fb4a0, treated as adapted: shaped like BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1fb4a0 Unit1fb4a0::ClearBuffers1fb4a0
#include "Unit1fb4a0.h"

// Deallocates each non-null buffer in the three-element array and resets its count to zero.
void Unit1fb4a0::ClearBuffers1fb4a0()
{
    for (std::size_t i = 0; i < 3; ++i) {
        if (buffers[i].data) {
            buffers[i].Deallocate();
            buffers[i].count = 0;
        }
    }
}
